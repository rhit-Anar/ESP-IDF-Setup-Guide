# ESP-IDF Setup Guide
This documentation will help how to set ESP-IDF on you computer without requiring any pre knowledge of coding. An easy step-by-step steup.
**Useful notation used for this document:**
|Notation|Explanation|
|--------|-----------|
|(*)| Means recommended|
|When you open a new terminal| You must run the export script every time you open a new terminal because it only creates a temporary bridge to the ESP-IDF tools; once the terminal is closed, the environment variables are cleared, and the system no longer recognizes the idf.py command.|
## Small Note before everything: 
There are **two ways** to download the ESP-IDF platform where you will be able to simply build and flash you code.
   1. **Manual way**- Using PowerShell (Command Terminal) (*) 
      This is where you download the tools directly and manage them via Powershell. 
         - [x] Have the total control over what is happenning in every file.
         - [x] Can see every error message directly, so easy to debug and when you have envirement issue.
         - [x] Used with Git or other custom build script.
         - [ ] **BUT** you have manually run . .\export.ps1 in every new terminal to wake up the idf tools. 
      
   3. **Authomatic way**- The VS Code Extention
      This where you download the ESP-IDF as extention to VS code.
      - [x] Auto easy set up the menuconfig inside the editor.
      - [x] Uses simple buttons in VS code to flash and build scripts. (it handles export.ps1 automatically.)
      - [ ] **BUT** for debugging path errors like python and idf_tool_path error it is hard to fix beasue they are set in JSON file somewhere.
> [!IMPORTANT]
> This documnet only show how to install and set up the ESP-DF platform as **Manual Way** as we shown below.
## 1. Things to download on your computer before download ESP-IDF
   - [x] To check if you have downloaded Python 3.11, Open **PowerShell** on your PC. Run the command:
         ```
         python --version
         ```
   - [x] If not, Download Python 3.11. Link: [Download Python Click Here!](https://www.python.org/ftp/python/3.11.7/python-3.11.7-amd64.exe). (It is usually downloaded in Download folder.)
   - [x] In downloading process, make sure click on **Add Python to environment variables**.
   - [x] If you forgot to add or not sure abut it's PATH, click on the the downloaded link again,
      1. Select **Modify**
      2. Click **Next** for Optional feature and on advanced option
      3. click **Add Python to environment variables**.
      4. Then click **Install**
   - [x] Then close the power shell and open new powershell again to see the updated path/version and run the command again.
      ```
      python --version
      ```
   - [x] As a result You will see something like this.
         <p align="left">
            <img width="348" height="50" alt="image" src="https://github.com/user-attachments/assets/e8e3ff71-f0ac-4ffb-8fde-aeca5f4df4eb" />
         </p>
   - [x] Install VS code: usually it is downloaded. 
## 2. Downloading ESP_IDF Manually
   1. EDP-IDF Tools 5.4.3 version (This version supports these esp devices: **ESP32, ESP32-C2, ESP32-C3, ESP32-C6, ESP32-H series, ESP32-S series, ESP32-P Series**).
   2. When you download the the tool, make sure to enable the Chip targets you want to use during the download progress.
      <p align="left">
      <img width="336" height="216" alt="image" src="https://github.com/user-attachments/assets/8a90d9bb-e362-4648-a473-545ee78d0138" />
      </p>
   3. Download ESP-IDF 5.4.3 make sure to click the correct version. (**Please make sure the version supports you board. Defend on which board you are using, you may want to download other version.**)
      To download ESP-IDF tool Click on the link: https://dl.espressif.com/dl/esp-idf/?idf=4.4
   4. Make sure to download the folder you desire. For this case, I downloaded it in C drive.
   5. After downloading you would see path. For an example: **C:\Espressif\frameworks\esp-idf-v5.4.3**
   6. Make sure you have **export.ps1** file in your path such as: C:\Espressif\frameworks\esp-idf-v5.4.3 **look for => export.ps1**.
> [!NOTE]
> AT THIS POINT YOU HAVE  SUCCESSFULLY DOWNLOADED THE ESP-IDF TOOL. IN SECTION 3, IT SHOWS HOW TO RUN YOUR CODE FROM POWER SHELL.
        
## 3. HOW TO BUILD AND FLASH YOUR CODE FROM POWERSHELL
> [!IMPORTANT]
> ALWAYS DO THIS BEFORE USE IDF TOOL!!! **When you open a new terminal**.
   1. Open PowerShell on your computer.
   3. **When you open a new terminal**
      - Navigate to path below on your powershell to set up the connection to **IDF** tool. **If you have downloaded different version, please change the version number below**.
         ```
         cd C:\Espressif\frameworks\esp-idf-v5.4.3
         ```
      - (**When you open a new terminal**) We want to wake up the esp-idf tool, but the windows security blocks them. So, to allow temporarily access to terminal, please run the code below. 
         ```
         Set-ExecutionPolicy -ExecutionPolicy Bypass -Scope Process
         ```
      - (**When you open a new terminal**) After allowing temporary access to the terminal, we want to wake up the IDF tool, run the command below.
         ```
         & .\export.ps1
         ```
   7. To make sure you have the correct version ( for my case: v5.4.3) run: if it says 1.0... something it is okay.
   ```
   idf.py --version
   ```
<p align="left">
<img width="327" height="49" alt="image" src="https://github.com/user-attachments/assets/fa19a9d1-3199-4ff6-bb10-5936480e5020" />
</p>

> [!TIP]
> If you have trouble running the idf.py command, make sure you have connceted to the ESP-IDF to your terminal. Run the export command line look for **When you open a new terminal** .
> [!NOTE]
> AT THIS POINT YOU HAVE CONNECETED TO IDF TOOL AND READY TO COMPILE and RUN YOUR CODE. NEXT NAVIGATE TO YOUR MAIN CODE SOURCE FILE.

   8. Then go to your project if you have one. If not, you can run example codes from ESP-IDF folder. Search the PATH below in your file Explorer, the choose you example code. Open in you VS. 
      if you have downloaded in C drive:
       ```
      C:\Espressif\frameworks\esp-idf-v5.5.1-2\examples\get-started
       ```
   9. Make sure target set to your target device (my target is esp32p4). If not, run:
       ```
       idf.py set-target esp32p4
       ```
   11. (*) If you have build the project before, clean before flash (it will remove old build folder), run:
       ```
       idf.py fullclean
       ```
   14. Then build:
       ```
       idf.py build
       ```
   16. Then to flash it to your device and open the terminal, run the command below. (Instead of x put the COM number).
       ```
       idf.py -p COMx flash monitor
       ```
   17. To run seperate falsh and monitor command here they are:
      ```
      idf.py -p COMx flash
      ```
      To opem a monitor:
      ```
      idf.py monitor 
      ```
   18. To exit the terminal click --> **Ctrl[+]**
>[!TIP]
>if you have a trouble with running the commands, go to part **When you open a new terminal**:

## 3. ESP-IDF Terminal:
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








   
