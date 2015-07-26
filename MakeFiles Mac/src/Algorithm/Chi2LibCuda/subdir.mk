################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Algorithm/Chi2LibCuda/Chi2LibCuda.cpp \
../src/Algorithm/Chi2LibCuda/Chi2LibCudaFFT.cpp \
../src/Algorithm/Chi2LibCuda/Chi2LibCudaFFTCache.cpp \
../src/Algorithm/Chi2LibCuda/Chi2LibCudaHighDensity.cpp \
../src/Algorithm/Chi2LibCuda/Chi2LibCudaQhull.cpp 

OBJS += \
./src/Algorithm/Chi2LibCuda/Chi2LibCuda.o \
./src/Algorithm/Chi2LibCuda/Chi2LibCudaFFT.o \
./src/Algorithm/Chi2LibCuda/Chi2LibCudaFFTCache.o \
./src/Algorithm/Chi2LibCuda/Chi2LibCudaHighDensity.o \
./src/Algorithm/Chi2LibCuda/Chi2LibCudaQhull.o 

CPP_DEPS += \
./src/Algorithm/Chi2LibCuda/Chi2LibCuda.d \
./src/Algorithm/Chi2LibCuda/Chi2LibCudaFFT.d \
./src/Algorithm/Chi2LibCuda/Chi2LibCudaFFTCache.d \
./src/Algorithm/Chi2LibCuda/Chi2LibCudaHighDensity.d \
./src/Algorithm/Chi2LibCuda/Chi2LibCudaQhull.d 


# Each subdirectory must supply rules for building sources it contributes
src/Algorithm/Chi2LibCuda/%.o: ../src/Algorithm/Chi2LibCuda/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/include -I/usr/local/include/ImageMagick-6 -O3 -mtune=native -mfpmath=sse -ftree-vectorize -funroll-loops -ffast-math -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


