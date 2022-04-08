# Update MDK-Middleware File System configuration files based on provided interface settings described in the board layer
sed -i "s/MC0_MCI_DRIVER    *[^ ]*/MC0_MCI_DRIVER          $CMSIS_MCI_DRIVER/"     "RTE/File_System/FS_Config_MC_0.h"
if [ ! -z ${CMSIS_MCI_CACHE_ADDR} ]; then
sed -i "s/MC0_CACHE_RELOC   *[^ ]*/MC0_CACHE_RELOC         1/"                     "RTE/File_System/FS_Config_MC_0.h"
sed -i "s/MC0_CACHE_ADDR    *[^ ]*/MC0_CACHE_ADDR          $CMSIS_MCI_CACHE_ADDR/" "RTE/File_System/FS_Config_MC_0.h"
fi
