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

# update layer and clayer collection
layer+=("Board")
clayer+=" ../../${layerpath}/Board/${board}/Board.clayer"

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
  # update layer and clayer collection
  layer+=("Module")
  clayer+=" ../../${layerpath}/Module/${module}/Module.clayer"
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
  # update layer and clayer collection
  layer+=("Socket")
  clayer+=" ../../${layerpath}/Socket/${socket}/Socket.clayer"
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
  # update layer and clayer collection
  layer+=("RTOS")
  clayer+=" ../../${layerpath}/RTOS/${rtos}/RTOS.clayer"
fi

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

# read layer defines
for item in ${layer[@]}
do
  name="${item,,}_define"
  if [ -f $name ]
  then
    source $name  
  fi  
done

# execute layer configure
for item in ${layer[@]}
do
  name="${item,,}_configure.sh"
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
  echo >> README.md
  if [ ! -z ${rtos} ]
  then
    cat layer.RTOS.md >> README.md
    echo >> README.md
    echo >> README.md
  fi
  if [ ! -z ${socket} ]
  then
    cat layer.Socket.md >> README.md
    echo >> README.md
    echo >> README.md
  fi
  if [ ! -z ${module} ]
  then
    cat layer.Module.md >> README.md
    echo >> README.md
    echo >> README.md
  fi
  cat layer.Board.md >> README.md
fi

#remove layer meta files
for item in ${layer[@]}
do
  rm -f "layer.${item}.md"
  rm -f "${item,,}_define"
  rm -f "${item,,}_configure.sh"
  rm -f "${item}.clayer"
done

# set cprj description
description=$(head -n 1 README.md)
sed -i "s|Automatic generated project|${description}|" "${app}.cprj"


popd

popd
 
exit 0
