# ESP-IDF Setup Guide
This documentation will help how to set ESP-IDF on you computer without requiring any pre knowledge. An easy step-by-step steup.
Useful notation used for this document:
(*)--> recommended
## Small Note before everything: 
There are **two ways** to download the ESP-IDF platform where you will be able to simply build and flash you code.
   1. **Manual way**- The Command Line (*)
      This is when you download the IDF, compilers and python in to a folder it controls, which in our case we are downloading a folder espressif. 
         - [x] Have the total control over what is happenning in every file.
         - [x] Can see every error message directly, so easy to debug and when you have envirement issue.
         - [x] Used with Git or other custom build script.
         - [ ] **BUT** you have manually run . .\export.ps1 in every new terminal to wake up the idf tools. 
      
   3. **Authomatic way**- The VS Code Extention
      - [x] Auto easy set up the menuconfig inside the editor.
      - [x] Uses simple buttons in VS code to flash and build scripts. (it handles export.ps1 automatically.)
      - [ ] **BUT** for debugging path errors like python and idf_tool_path error it is hard to fix beasue they are set in JSON file somewhere.
> [!IMPORTANT]
> We are installing and setting up the ESP-DF platform as Manual Way as we shown below. 
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
## What to chnage in your given code:
In your code: Look for idf_Something.yml file in your main folder. (usually same folder as the main.c).
Then you will see it is starts with dependencies: ....
Look for a line: 
   ```
   nimble_peripheral_utils:
   path: XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
   ```
Then go to your Folder and look for where is your nimble_peripheral_utils file is located in your folder. And copy that. But here
I have copied the path below with different veersion of ESP_IDFs and you cn just copy and paste.
**Remember to chnage the C:\ if you didn't downloaded in your C drive. Easy way is just directly copy the path from your folder**.

Version of ESP_IDF: **esp-idf-v5.5.1-2**.
```
C:\Espressif\frameworks\esp-idf-v5.5.1-2\examples\bluetooth\nimble\common\nimble_peripheral_utils
```
Version of ESP_IDF: **esp-idf-v5.4.3**.
```
C:\Espressif\frameworks\esp-idf-v5.4.3\examples\bluetooth\nimble\common\nimble_peripheral_utils
```
## What to Run in Power Shell Teminal: (Assumed ESP_IDF is in C drive!!!, change if your location is different.)
Please go to your esp_IDF folder:
```
cd  C:\Espressif\frameworks
```
Since we may have different version run the next code to go to your versuion of IDF:
```
ls
```
Once you have done, You may see different versions, (I recommend have only one version, or else something it confuses the path.)
<p align="left">
<img width="678" height="216" alt="image" src="https://github.com/user-attachments/assets/74f1fd6d-c27c-4882-8044-ecf638eeb5a8" />
</p>
Then go to that folder, change the version number below with what you have. Easy trick, if you type **e** then click **Tab** it completes auto for you. 

```
cd esp-idf-v5.5.1-2
```
After you are in the correct esp_idf folder run below command in Power Shell Teminal. (I recommend us it from the search app not from VS code.)

Run code below, because the terminal is being over protective and this below line give you one time access to run the code. 
```
Set-ExecutionPolicy -ExecutionPolicy Bypass -Scope Process
```
Then run the code below. Sometimes the the version is different like, ..\export... or something . If that is is the case google. 
```
.\export.ps1
```
Then now go back to your Main code file folder.

## How to run your code
Please go to your main code file folder in power shell.Replace the the whole C:\Users\X with your path to the code. 

```
cd C:\Users\X
```

To build:
```
idf.py build
```
To flash and show the monitor:
```
idf.py -p COMx flash monitor
```
Now you should see in the terminal what should be printed in your code. 
>[!TIP]
>If u see any Nimble related error, make sure your path is correct because I had the same error, and it was indeed the wrong path for me. Eventhough it it says you should configure the bluetooth manually, I reccommend just please the path!
>Because if numble pathis wrong it down't know how to find the nimble.h file located, it will think it doesn't exits. 








   
