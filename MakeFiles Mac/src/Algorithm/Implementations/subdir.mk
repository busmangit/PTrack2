################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
CPP_SRCS += \
../src/Algorithm/Implementations/Chi2Algorithm.cpp \
../src/Algorithm/Implementations/Chi2HDAlgorithm.cpp

OBJS += \
./src/Algorithm/Implementations/Chi2Algorithm.o \
./src/Algorithm/Implementations/Chi2HDAlgorithm.o

CPP_DEPS += \
./src/Algorithm/Implementations/Chi2Algorithm.d \
./src/Algorithm/Implementations/Chi2HDAlgorithm.d


# Each subdirectory must supply rules for building sources it contributes
src/Algorithm/Implementations/%.o: ../src/Algorithm/Implementations/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/include -I/usr/local/include/ImageMagick-6 -DMAGICKCORE_QUANTUM_DEPTH=16 -DMAGICKCORE_HDRI_ENABLE=0 -O3 -mtune=native -mfpmath=sse -ftree-vectorize -funroll-loops -ffast-math -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
