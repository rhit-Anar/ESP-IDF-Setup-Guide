
idf_component_register(
    SRCS
        "main.c"
        #simple hello word 
        # "hello_world/hello_world.c"
        #ble staffs
        # "bluetooth/nimBLE_GATT_Server/src/nimBLE_gatt_server_setup.c"
        # "bluetooth/nimBLE_GATT_Server/src/gap.c"
        # "bluetooth/nimBLE_GATT_Server/src/gatt_svc.c"
        # "bluetooth/nimBLE_GATT_Server/src/heart_rate_mock.c"
        # "bluetooth/nimBLE_GATT_Server/src/led.c"
        #wifi
         "wifi/station/src/station_example_main.c"
    INCLUDE_DIRS
        "."
        # "hello_world"
        # "bluetooth/nimBLE_GATT_Server/include"
        "wifi/station/include"
       REQUIRES
        # bt
        nvs_flash
        esp_wifi
        esp_event
        esp_netif
)