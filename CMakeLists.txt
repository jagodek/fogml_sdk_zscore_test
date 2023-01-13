cmake_minimum_required(VERSION 3.20.0)
project(FogML-SDK-zscore-test)

add_library(fogml_sdk 
    src/fogml_sdk/anomaly/fogml_anomaly.c
    src/fogml_sdk/anomaly_rt/fogml_lof.c
    src/fogml_sdk/anomaly_rt/fogml_reservoir.c
    src/fogml_sdk/anomaly_rt/fogml_zscore.c
    src/fogml_sdk/ports/fogml_ports_zephyr.c
    src/fogml_sdk/dsp/fogml_dsp.c
    src/fogml_sdk/scaler/fogml_scaler.c
)

add_executable(test src/main.c)

target_link_libraries(test PRIVATE fogml_sdk)