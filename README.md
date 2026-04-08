# ESP-IDF Setup Guide
This documentation will help how to set ESP-IDF on you computer without requiring any pre knowledge. An easy step-by-step steup.
## Make sure you have these downloaded on your computer:
- [ ] To check if you have downloaded Python 3.11, Open **PowerShell** on your PC.Run the command:
   ```
   python --version
   ```
   - [ ] If not, Download Python 3.11. Link: [Download Python Click Here!](https://www.python.org/ftp/python/3.11.7/python-3.11.7-amd64.exe). (It is usually downloaded in Download folder.)
   - [ ] When Downloading make sure click on **Add Python to environment variables**.
   - [ ] If you have forgot to add it to the PATH, click on the the downloaded link again, and select **Modify**, then hit **Next** for Optional feature and on advanced option, click **Add Python to environment variables**. Then click **Install**
   - [ ] Then close the power shell and open new powershell again and run the command again.
      ```
      python --version
      ```
   - [ ] As a result You will see something like this.
         <p align="left">
            <img width="348" height="50" alt="image" src="https://github.com/user-attachments/assets/e8e3ff71-f0ac-4ffb-8fde-aeca5f4df4eb" />
         </p>
- [ ] Install VS code: usually it is downloaded. 
## Downloading ESP_IDF:
1. Download EDP-IDF Tools 5.4.3 version (Depend which ESP32 board or another board ypu are working with, It is recommended to check which version of IDF yourd supports. This version works for ESP32P4 NANO).
   Click on the link: [ Download ESP-IDF 5.4.3 make sure to click the correct version ](https://dl.espressif.com/dl/esp-idf/?idf=4.4)
3. Make sure to download the folder you desire. For this case, I downloaded it in C drive.
4. After downloading you would see path like: C:\Espressif\frameworks\esp-idf-v5.4.3
5. I recommend doing everything in Windows PowerShell because it is easier than doing it in the ESP-IDF terminal.
6. Make sure you have export.ps1 in your path such as: C:\Espressif\frameworks\esp-idf-v5.4.3 => export.ps1.
## ESP-IDF Terminal:
1. After finished downloading the ESP-IDF terminal will be pop out.
2. Then go to the project folder you want to run. 
3. To delete the build folder:
   ```
   rmdir /s /q build
   ```
4. Deletes the old configuration
   ```
   del sdkconfig
   ```
6. set the target descired board. For this exampl, we use esp32p4.
   ```
   idf.py set-target esp32p4
   ```
7. Replace x for Port number. Go to **device Manager** -> **Port**
   ```
   idf.py -p COMx flash monitor
   ```
8. To exit the terminal click --> **Ctrl[+]**
>[!TIP]
>If you are having ny issue with sdkconfig file does not exists or incorrect version error run below commands
   After running the command below, Click S for save and Q for quit. 
   ```
   idf.py menuconfig
   ```
   To manually configure the ver, open the config file in the NOTE, then **Ctrl+F**, search for **CONFIG_ESP_REV_MIN_FULL**. in our case we set 1 to 100. 
   ```
   notepad sdkconfig
   ```
   
   
      
## PowerShell:
1. Open PowerShell on you computer.
2. Navigate to
   ```
   cd C:\Espressif\frameworks\esp-idf-v5.4.3
   ```
4. Then run:
   ```
   & .\export.ps1
   ```
6. To make sure you have v5.4.3 run: if it says 1.0... something it is okay.
   ```
   idf.py --version
   ```
8. Then go to your project. For example, my project looks like:
   <img width="441" height="375" alt="image" src="https://github.com/user-attachments/assets/bc1a7da9-c2b8-4548-9e03-ebe4909d02f5" />
9. Make sure target set to esp32p4. If not, run:
    ```
    idf.py set-target esp32p4
    ```
11. If you have run the project before, i recommend clean before flash, run:
    ```
    idf.py full clean
    ```
14. Then build:
    ```
    idf.py build
    ```
16.  Instead of x put the COM number:
    ```
    idf.py -p COMx flash monitor
    ```

>[!TIP]
>if you have a trouble with running the commands, go to Powershell, run:
   ```
   Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope Process 
   ```
   Then go to path:
   ```
   cd C:\Espressif\frameworks\esp-idf-v5.4.3 
   ```
   Then follow the following commands:
   ```
   & .\export.ps1 
   ```
   ```
   cd C:\exampleIDF\newesp32p4 
   ```
   ```
   idf.py build
   ```
   ```
   idf.py -p COMx flash
   ```
   ```
   idf.py monitor 
   ```

## Other issues:
Python Virtual Environment: python.exe make sue in esp-idf.
$env:IDF_PATH  --> to check if idf path is correct directiny pinting to

# ESP-IDF Bluetooth setup instruction
Assumed: you have an working file of codes that u want to run on your machine. :)

In your code: Look for idf_Something.yml file in your main folder. (usually same folder as the main.c).
Then you will see it is starts with dependencies: ....
Look for a line: 
   ```
   nimble_peripheral_utils:
   path: XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
   ```
Then go to your Folder and look for where is your nimble_peripheral_utils file is located in your folder. 
I have copied the path below with different veersion of ESP_IDF:
Version of ESP_IDF: **esp-idf-v5.5.1-2**
```
C:\Espressif\frameworks\esp-idf-v5.5.1-2\examples\bluetooth\nimble\common\nimble_peripheral_utils
```
Version of ESP_IDF: **esp-idf-v5.4.3**
```
C:\Espressif\frameworks\esp-idf-v5.4.3\examples\bluetooth\nimble\common\nimble_peripheral_utils
```



   
