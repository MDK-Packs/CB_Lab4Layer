#!/bin/bash

# header
echo "Generate project from layers"

# usage
usage() {
  echo "Usage:"
  echo "  gen_proj.sh App=<AppLayer>"
  echo "              Board=<BoardLayer>"
  echo "              [Module=<ModuleLayer>]"
  echo "              [Socket=<SocketLayer>]"
  echo "              [RTOS=<RTOSLayer>]"
  echo "              [--layer=<LayerPath>]"
  echo ""
  echo "  App=<AppLayer>           : Application layer"
  echo "  Board=<BoardLayer>       : Board layer"
  echo "  Module=<ModuleLayer>     : Module layer (optional)"
  echo "  Socket=<SocketLayer>     : Socket layer (optional)"
  echo "  RTOS=<SocketLayer>       : RTOS layer (optional)"
  echo "  --layer=<LayerPath>      : Layer directory (default=Layer)"
}

# silent pushd
pushd () {
  command pushd "$@" > /dev/null
}

# silent popd
popd () {
  command popd "$@" > /dev/null
}

# arguments
if [ $# -eq 0 ]
then
  usage
  exit 0
fi

for i in "$@"
do
  case $i in
    App=*)
      app="${i#*=}"
      shift
    ;;
    Board=*)
      board="${i#*=}"
      shift
    ;;
    Module=*)
      module="${i#*=}"
      shift
    ;;
    Socket=*)
      socket="${i#*=}"
      shift
    ;;
    RTOS=*)
      rtos="${i#*=}"
      shift
    ;;
    --layer=*)
      layerpath="${i#*=}"
      shift
    ;;
    *)
      usage
      exit 1
    ;;
  esac
done

# check if Application layer is specified
if [ -z ${app} ]
then
  echo "error: missing <AppLayer>"
  usage
  exit 1
fi

# check if Board layer is specified
if [ -z ${board} ]
then
  echo "error: missing <BoardLayer>"
  usage
  exit 1
fi

# set default layer directory if not specified
if [ -z ${layerpath} ]
then
  layerpath="Layer"
fi

# check if Application layer exists
if [ ! -d "${layerpath}/App/${app}" ]
then
  echo "error: Application layer <${app}> not found in <${layerpath}/App>"
  exit 1
fi

# set layer and clayer collection
layer=("App")
clayer="../../${layerpath}/App/${app}/App.clayer"

# check if Board layer exists
if [ ! -d "${layerpath}/Board/${board}" ]
then
  echo "error: Board layer <${board}> not found in <${layerpath}/Board>"
  exit 1
fi

# set target name
target="${board}"

# check if Module layer is specified and exists
if [ ! -z ${module} ]
then
  if [ ! -d "${layerpath}/Module/${module}" ]
  then
    echo "error: Module layer <${module}> not found in <${layerpath}/Module>"
    exit 1
  fi
  # update target name
  target+="_${module}"
fi

# check if Socket layer is specified and exists
if [ ! -z ${socket} ]
then
  if [ ! -d "${layerpath}/Socket/${socket}" ]
  then
    echo "error: Socket layer <${socket}> not found in <${layerpath}/Socket>"
    exit 1
  fi
  # update target name
  target+="_${socket}"
fi

# check if RTOS layer is specified and exists
if [ ! -z ${rtos} ]
then
  if [ ! -d "${layerpath}/RTOS/${rtos}" ]
  then
    echo "error: RTOS layer <${rtos}> not found in <${layerpath}/RTOS>"
    exit 1
  fi
  # update target name
  target+="_${rtos}"
fi

# check if RTOS layer is specified
if [ ! -z ${rtos} ]
then
  # update layer and clayer collection
  layer+=("RTOS")
  clayer+=" ../../${layerpath}/RTOS/${rtos}/RTOS.clayer"
fi

# check if Socket layer is specified
if [ ! -z ${socket} ]
then
  # update layer and clayer collection
  layer+=("Socket")
  clayer+=" ../../${layerpath}/Socket/${socket}/Socket.clayer"
fi

# check if Module layer is specified
if [ ! -z ${module} ]
then
  # update layer and clayer collection
  layer+=("Module")
  clayer+=" ../../${layerpath}/Module/${module}/Module.clayer"
fi

# update Board layer and clayer collection
layer+=("Board")
clayer+=" ../../${layerpath}/Board/${board}/Board.clayer"

# create application directory if it does not exist
if [ ! -d "${app}" ]
then
  mkdir "${app}"
fi

# go to application directory
pushd "${app}"

# create target directory if it does not exist
if [ ! -d "${target}" ]
then
  mkdir "${target}"
fi

# go to target directory
pushd "${target}"

echo "Output:  ${app}/${target}"
echo "Project: ${app}.cprj"   

# compose project from layers
cbuildgen compose "${app}.cprj" ${clayer}

# export layer defines
export ARDUINO_USART_NUMBER=$(grep -o '<provides id="A_UART" value="."' "${app}.cprj" | grep -o 'value="."' | grep -o '\([0-9.]*\)')
export ARDUINO_SPI_NUMBER=$(grep -o '<provides id="A_SPI" value="."' "${app}.cprj" | grep -o 'value="."' | grep -o '\([0-9.]*\)')

# export MCI settings
       CMSIS_MCI_VALUE=$(       grep '<provides id="C_MCI"' "${app}.cprj" | grep -o 'value=".*"' | grep -o '".*"' | sed -E 's/"//g')
export CMSIS_MCI_DRIVER=$(      echo $CMSIS_MCI_VALUE  | sed -E 's/([^A-Za-z0-9]*([A-Za-z0-9]*)){1}.*/\2/')
export CMSIS_MCI_CACHE_ADDR=$(  echo $CMSIS_MCI_VALUE  | sed -E 's/([^A-Za-z0-9]*([A-Za-z0-9]*)){2}.*/\2/')

# execute layer configure
for item in ${layer[@]}
do
  name="layer.${item}.sh"
  if [ -f $name ]
  then
    ./$name  
  fi  
done

# cbuildgen version 0.9.0
if [ ! -z "$(grep 0.9.0 <<< $(cbuildgen))" ]
then
  # compose README.md
  cat layer.App.md > README.md
  echo >> README.md
  if [ ! -z ${rtos} ]
  then
    cat layer.RTOS.md >> README.md
    echo >> README.md
  fi
  if [ ! -z ${socket} ]
  then
    cat layer.Socket.md >> README.md
    echo >> README.md
  fi
  if [ ! -z ${module} ]
  then
    cat layer.Module.md >> README.md
    echo >> README.md
  fi
  cat layer.Board.md >> README.md
fi

#remove layer meta files
for item in ${layer[@]}
do
  rm -f "layer.${item}.md"
  rm -f "layer.${item}.sh"
  rm -f "${item}.clayer"
done

# replace generated cprj description with <name> and <description>
#  <name> is derived from "App" layer's title
#  <description> is derived from "App" layer's description
name=$(sed -nr 's|.*<layer name="App" title="(.*)">|<name>\1</name>|p' "${app}.cprj")
description=$(sed -n '/<layer name="App"/,/<description>/p' "${app}.cprj" | sed -n '/<description>/p' | sed 's/^ */    /')
sed -i "s|<description>Automatic generated project</description>|${name}\n${description}|" "${app}.cprj"

popd

popd
 
exit 0
