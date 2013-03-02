################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../GlcdRectangle/GlcdRectangle.cpp 

OBJS += \
./GlcdRectangle/GlcdRectangle.o 

CPP_DEPS += \
./GlcdRectangle/GlcdRectangle.d 


# Each subdirectory must supply rules for building sources it contributes
GlcdRectangle/%.o: ../GlcdRectangle/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/usr/share/arduino/libraries/Wire/utility -I/usr/share/arduino/libraries/Wire -I/usr/share/arduino/hardware/arduino/variants/standard -I/usr/share/arduino/hardware/arduino/cores/arduino -I"/storage/microcontroller/arduino/library/glcd/GlcdBitmapFont" -I"/storage/microcontroller/arduino/library/glcd/GlcdBitmapImage" -I"/storage/microcontroller/arduino/library/glcd/GlcdBitmapRender" -I"/storage/microcontroller/arduino/library/glcd/GlcdDrawer" -I"/storage/microcontroller/arduino/library/glcd/GlcdGraphicState" -I"/storage/microcontroller/arduino/library/glcd/GlcdPoint" -I"/storage/microcontroller/arduino/library/glcd/GlcdRectangle" -I"/storage/microcontroller/arduino/library/glcd/GlcdSimpleText" -I"/storage/microcontroller/arduino/library/glcd/GlcdText" -I"/storage/microcontroller/arduino/library/glcd/GlcdTextLine" -I"/storage/microcontroller/arduino/driver/glcd/Glcd" -I"/storage/microcontroller/arduino/driver/glcd/GlcdStraight" -I"/storage/microcontroller/arduino/driver/glcd/GlcdWire" -I"/storage/microcontroller/arduino/library/io/BufferedInputStream" -I"/storage/microcontroller/arduino/library/io/BufferedOutputStream" -I"/storage/microcontroller/arduino/library/io/ByteArrayInputStream" -I"/storage/microcontroller/arduino/library/io/ByteArrayOutputStream" -I"/storage/microcontroller/arduino/library/io/ByteArraySeekableInputStream" -I"/storage/microcontroller/arduino/library/io/Closeable" -I"/storage/microcontroller/arduino/library/io/DataInput" -I"/storage/microcontroller/arduino/library/io/DataInputStream" -I"/storage/microcontroller/arduino/library/io/DataOutput" -I"/storage/microcontroller/arduino/library/io/DataOutputStream" -I"/storage/microcontroller/arduino/library/io/ExternalEepromInputStream" -I"/storage/microcontroller/arduino/library/io/ExternalEepromOutputStream" -I"/storage/microcontroller/arduino/library/io/ExternalEepromSeekableInputStream" -I"/storage/microcontroller/arduino/library/io/FilterInputStream" -I"/storage/microcontroller/arduino/library/io/FilterOutputStream" -I"/storage/microcontroller/arduino/library/io/HardwareSerialInputStream" -I"/storage/microcontroller/arduino/library/io/HardwareSerialOutputStream" -I"/storage/microcontroller/arduino/library/io/InputStream" -I"/storage/microcontroller/arduino/library/io/nbproject" -I"/storage/microcontroller/arduino/library/io/OutputStream" -I"/storage/microcontroller/arduino/library/io/PgmspaceInputStream" -I"/storage/microcontroller/arduino/library/io/PgmspaceSeekableInputStream" -I"/storage/microcontroller/arduino/library/io/RandomAccess" -I"/storage/microcontroller/arduino/library/io/RandomAccessByteArray" -I"/storage/microcontroller/arduino/library/io/RandomAccessExternalEeprom" -I"/storage/microcontroller/arduino/library/io/RandomAccessResource" -I"/storage/microcontroller/arduino/library/io/ResourceInputStream" -I"/storage/microcontroller/arduino/library/io/ResourceOutputStream" -I"/storage/microcontroller/arduino/library/io/ResourceSeekableInputStream" -I"/storage/microcontroller/arduino/library/io/Seekable" -I"/storage/microcontroller/arduino/library/io/SeekableInputStream" -I"/storage/microcontroller/arduino/library/io/SerialInputStream" -I"/storage/microcontroller/arduino/library/io/SerialOutputStream" -I"/storage/microcontroller/arduino/library/io/SoftwareSerialInputStream" -I"/storage/microcontroller/arduino/library/io/SoftwareSerialOutputStream" -I"/storage/microcontroller/arduino/library/io/WireInputStream" -I"/storage/microcontroller/arduino/library/io/WireOutputSream" -Wall -Os -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


