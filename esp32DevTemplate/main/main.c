//Author: Anar Amartuvshin
#include <stdio.h>
#include "app_config.h"

#if USE_HELLO_WORLD
#include "hello_world/hello_world.h"
#endif

#if USE_BLE
#include "nimBLE_gatt_server_setup.h"
#endif
void station_wifi_main(void);
void ble_gatt_main(void);
void app_main(void)
{
    printf("ESP32 Starter Project\n");
//Toggle Mode for hello wolrd, to remove it you can go to the app_config.h file and set the hello world to 0. T
#if USE_HELLO_WORLD
    hello_world_run();
#endif
//=============================================================================================================

//BLE_gatt_server setup----------------------------------------------------------------------------------------
#if USE_BLE
    ble_gatt_main();
    printf("Calling the ble gatt server!");
#endif
//=============================================================================================================
//Wifi station set up -----------------------------------------------------------------------------------------
#if USE_WIFI
    station_wifi_main();
#endif
//=============================================================================================================
}