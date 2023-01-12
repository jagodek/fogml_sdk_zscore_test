cmake_minimum_required(VERSION 3.20.0)
project(FogML-SDK-zscore-test)

# set(fogml_sources
#     src/fogml_sdk/anomaly/fogml_anomaly.c
#     src/fogml_sdk/anomaly_rt/fogml_lof.c
#     src/fogml_sdk/anomaly_rt/fogml_reservoir.c
#     src/fogml_sdk/anomaly_rt/fogml_zscore.c
#     src/fogml_sdk/ports/fogml_ports_zephyr.c
#     src/fogml_sdk/dsp/fogml_dsp.c
#     src/fogml_sdk/scaler/fogml_scaler.c
# )

# set(private_sources
#     src/main.c)

# target_sources(app PRIVATE ${private_sources} ${fogml_sources})

add_library(fogml_sdk 
    src/fogml_sdk/anomaly/fogml_anomaly.c
    src/fogml_sdk/anomaly_rt/fogml_lof.c
    src/fogml_sdk/anomaly_rt/fogml_reservoir.c
    src/fogml_sdk/anomaly_rt/fogml_zscore.c
    src/fogml_sdk/ports/fogml_ports_zephyr.c
    src/fogml_sdk/dsp/fogml_dsp.c
    src/fogml_sdk/scaler/fogml_scaler.c
)

add_executable(app src/main.c)

