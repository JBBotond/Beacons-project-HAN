# CROSS COMPILER SETTING
set(CMAKE_SYSTEM_NAME Generic)
cmake_minimum_required(VERSION 3.10.0)

if (NOT DEFINED SdkRootDirPath)
    SET(SdkRootDirPath ${CMAKE_CURRENT_LIST_DIR})
endif()

include(${CMAKE_CURRENT_LIST_DIR}/config.cmake)
include(${SdkRootDirPath}/cmake/toolchain/toolchain.cmake)

# THE VERSION NUMBER
SET (MCUXPRESSO_CMAKE_FORMAT_MAJOR_VERSION 2)
SET (MCUXPRESSO_CMAKE_FORMAT_MINOR_VERSION 0)

include(ide_overrides.cmake OPTIONAL)

if(CMAKE_SCRIPT_MODE_FILE)
  message("${MCUXPRESSO_CMAKE_FORMAT_MAJOR_VERSION}")
  return()
endif()


set(CMAKE_EXECUTABLE_LIBRARY_PREFIX)
set(CMAKE_EXECUTABLE_LIBRARY_SUFFIX)

# CURRENT DIRECTORY
set(ProjDirPath ${CMAKE_CURRENT_SOURCE_DIR})

set(EXECUTABLE_OUTPUT_PATH ${ProjDirPath}/${CMAKE_BUILD_TYPE})
set(LIBRARY_OUTPUT_PATH ${ProjDirPath}/${CMAKE_BUILD_TYPE})


project(template)

enable_language(ASM)

set(MCUX_BUILD_TYPES debug)

set(EXECUTABLE_OUTPUT_PATH ${ProjDirPath})
set(LIBRARY_OUTPUT_PATH ${ProjDirPath})
set(MCUX_SDK_PROJECT_NAME template.elf)

include(${ProjDirPath}/flags.cmake)

add_executable(${MCUX_SDK_PROJECT_NAME} 
"${ProjDirPath}/devices/MCX/MCXA/MCXA153/system_MCXA153.c"
"${ProjDirPath}/devices/MCX/MCXA/MCXA153/gcc/startup_MCXA153.S"
"${ProjDirPath}/components/misc_utilities/fsl_syscall_stub.c"
"${ProjDirPath}/components/misc_utilities/fsl_sbrk.c"
"${ProjDirPath}/components/misc_utilities/fsl_memcpy.S"
"${ProjDirPath}/examples/_boards/frdmmcxa153/ese_common/leds/leds.c"
"${ProjDirPath}/examples/_boards/frdmmcxa153/ese_common/switches/switches.c"
"${ProjDirPath}/examples/_boards/frdmmcxa153/ese_common/serial/serial.c"
"${ProjDirPath}/examples/_boards/frdmmcxa153/ese_common/serial/retarget.c"
"${ProjDirPath}/examples/ese_examples/general/template/main.c"
"${ProjDirPath}/examples/ese_common/fifo/fifo.c"
"${ProjDirPath}/mcux_config.h"
"${ProjDirPath}/mcuxsdk_version.h"
"${ProjDirPath}/devices/MCX/MCXA/MCXA153/fsl_device_registers.h"
"${ProjDirPath}/devices/MCX/MCXA/MCXA153/MCXA153.h"
"${ProjDirPath}/devices/MCX/MCXA/MCXA153/MCXA153_features.h"
"${ProjDirPath}/devices/MCX/MCXA/MCXA153/MCXA153_COMMON.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_ADC.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_AOI.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_CDOG.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_CMC.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_CRC.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_CTIMER.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_DEBUGMAILBOX.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_DMA.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_EIM.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_EQDC.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_ERM.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_FMC.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_FMU.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_FMUTEST.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_FREQME.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_GLIKEY.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_GPIO.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_I3C.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_INPUTMUX.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_LPCMP.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_LPI2C.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_LPSPI.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_LPTMR.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_LPUART.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_MRCC.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_OSTIMER.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_PORT.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_PWM.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_SCG.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_SPC.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_SYSCON.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_TRDC.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_USB.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_UTICK.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_VBAT.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_WAKETIMER.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_WUU.h"
"${ProjDirPath}/devices/MCX/MCXA/periph/PERI_WWDT.h"
"${ProjDirPath}/devices/MCX/MCXA/MCXA153/system_MCXA153.h"
"${ProjDirPath}/arch/arm/CMSIS/Core/Include/cmsis_compiler.h"
"${ProjDirPath}/arch/arm/CMSIS/Core/Include/cmsis_version.h"
"${ProjDirPath}/arch/arm/CMSIS/Core/Include/cmsis_gcc.h"
"${ProjDirPath}/arch/arm/CMSIS/Core/Include/m-profile/cmsis_gcc_m.h"
"${ProjDirPath}/arch/arm/CMSIS/Core/Include/core_cm33.h"
"${ProjDirPath}/arch/arm/CMSIS/Core/Include/m-profile/armv8m_mpu.h"
"${ProjDirPath}/arch/arm/CMSIS/Core/Include/tz_context.h"
"${ProjDirPath}/examples/_boards/frdmmcxa153/ese_common/board/board.h"
"${ProjDirPath}/examples/_boards/frdmmcxa153/ese_common/leds/leds.h"
"${ProjDirPath}/examples/_boards/frdmmcxa153/ese_common/switches/switches.h"
"${ProjDirPath}/examples/_boards/frdmmcxa153/ese_common/serial/serial.h"
"${ProjDirPath}/examples/ese_common/fifo/fifo.h"
"${ProjDirPath}/src/myheader.h"
"${ProjDirPath}/src/myheader.c"
"${ProjDirPath}/src/mymain.c"
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${ProjDirPath}/devices/MCX/MCXA/MCXA153
    ${ProjDirPath}/devices/MCX/MCXA/periph
    ${ProjDirPath}/arch/arm/CMSIS/Core/Include
    ${ProjDirPath}/arch/arm/CMSIS/Core/Include/m-profile
    ${ProjDirPath}/examples/_boards/frdmmcxa153/ese_common/board
    ${ProjDirPath}/examples/_boards/frdmmcxa153/ese_common/leds
    ${ProjDirPath}/examples/_boards/frdmmcxa153/ese_common/switches
    ${ProjDirPath}/examples/_boards/frdmmcxa153/ese_common/serial
    ${ProjDirPath}/examples/ese_examples/general/template
    ${ProjDirPath}/examples/ese_common/fifo
    ${ProjDirPath}/src
)


IF(NOT DEFINED TARGET_LINK_SYSTEM_LIBRARIES)  
    SET(TARGET_LINK_SYSTEM_LIBRARIES "-lm -lc -lgcc -lnosys")  
ENDIF()  

TARGET_LINK_LIBRARIES(${MCUX_SDK_PROJECT_NAME} PRIVATE -Wl,--start-group)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE ${TARGET_LINK_SYSTEM_LIBRARIES})

TARGET_LINK_LIBRARIES(${MCUX_SDK_PROJECT_NAME} PRIVATE -Wl,--end-group)

ADD_CUSTOM_COMMAND(TARGET ${MCUX_SDK_PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_OBJCOPY}
-Obinary ${EXECUTABLE_OUTPUT_PATH}/${MCUX_SDK_PROJECT_NAME} ${EXECUTABLE_OUTPUT_PATH}/template.bin)

set_target_properties(${MCUX_SDK_PROJECT_NAME} PROPERTIES ADDITIONAL_CLEAN_FILES "output.map;${EXECUTABLE_OUTPUT_PATH}/template.bin")

