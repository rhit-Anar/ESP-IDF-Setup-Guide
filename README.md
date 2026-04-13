# ESP-IDF Setup Guide - Lets Get Started
This documentation will help you set up ESP-IDF on your computer without prior coding knowledge—an easy step-by-step setup.
**Useful notation used for this document:**
|Notation|Explanation|
|--------|-----------|
|(*)| Means recommended, but it is optional|
## 1. Small Note before everything: 
There are **two ways** to download the ESP-IDF platform, allowing you to build and flash your code.
   - **Manual way**- Using PowerShell (Command Terminal) (*).\
     This is where you download the tools directly and manage them via Powershell. 
      - [x] Have total control over what is happening in every file.
      - [x] Can see every error message directly, so it's easy to debug and handle environment issues.
      - [x] Used with Git or other custom build scripts.
      - [ ] **BUT** you have manually run . .\export.ps1 in every new PowerShell terminal to wake up the idf tools. 
      
   - **Authomatic way**- The VS Code Extention
      This where you download the ESP-IDF as extention to VS code.
      - [x] Auto-easy sets up the menuconfig inside the editor.
      - [x] Uses simple buttons in VS Code to flash and build scripts. (It handles export.ps1 automatically).
      - [ ] **BUT** for debugging path errors like Python and IDF tool path errors, it is hard to fix because they are set in a JSON file somewhere.
> [!WARNING]
> This document only shows how to install and set up the ESP-DF platform using the **Manual Way** shown below.
## 2. Things to download on your computer before downloading ESP-IDF
   - [x] To check if you have downloaded Python 3.11, Open **PowerShell** on your PC. Run the command:
         ```
         python --version
         ```
   - [x] If not, Download Python 3.11. Link: [Download Python Click Here!](https://www.python.org/ftp/python/3.11.7/python-3.11.7-amd64.exe). (It is usually downloaded in Download folder.)
   - [x] In downloading process, make sure click on **Add Python to environment variables**.
   - [x] If you forgot to add or are not sure about its PATH, click on the downloaded link again,
      - Select **Modify**
      - Click **Next** for Optional feature and on Advanced option
      - click **Add Python to environment variables**.
      - Then click **Install**
   - [x] Then close PowerShell and open a new PowerShell window to see the updated path/version, and run the command again.
      ```
      python --version
      ```
   - [x] As a result You will see something like this.
      <p align="left">
         <img width="348" height="50" alt="image" src="https://github.com/user-attachments/assets/e8e3ff71-f0ac-4ffb-8fde-aeca5f4df4eb" />
      </p>
   - [x] Install VS code: usually it is downloaded. 
## 3. Downloading ESP_IDF Manually
   + EDP-IDF Tools 5.4.3 version (This version supports these esp devices: **ESP32, ESP32-C2, ESP32-C3, ESP32-C6, ESP32-H series, ESP32-S series, ESP32-P Series**).
   + When you download the tool, make sure to enable the Chip targets you want to use during the download process.
         <p align="left">
         <img width="336" height="216" alt="image" src="https://github.com/user-attachments/assets/8a90d9bb-e362-4648-a473-545ee78d0138" />
         </p>
   + Download ESP-IDF 5.4.3 make sure to click the correct version. (**Please make sure the version supports you board. Defend on which board you are using, you may want to download other version.**)
      To download ESP-IDF tool Click on the link: https://dl.espressif.com/dl/esp-idf/?idf=4.4
   + Make sure to download the folder you desire. For this case, I downloaded it to the C drive.
   + After downloading you should see path like this in your File Explorer. For an example: **C:\Espressif\frameworks\esp-idf-v5.4.3**
   + Make sure you have **export.ps1** file in your path such as: C:\Espressif\frameworks\esp-idf-v5.4.3 **look for => export.ps1**.
> [!NOTE]
> AT THIS POINT YOU HAVE  SUCCESSFULLY DOWNLOADED THE ESP-IDF TOOL. IN SECTION 5, IT SHOWS HOW TO CONNECT TO THE IDF tool from PowerShell.
## Sample Section      
## 4. BRIDGE CONNECTING BETWEEEN POWERSHELL AND IDF TOOL
> [!IMPORTANT]
>  ALWAYS DO THIS WHEN YOU OPEN A NEW TERMINAL! You must run the export script every time you open a new terminal, because it only creates a temporary bridge to the ESP-IDF tools; once the terminal closes, the environment variables are cleared, and the system no longer recognizes the idf.py command.
   1. Open PowerShell on your computer.
   2. When you open a new terminal.
      - Navigate to the path below on your PowerShell to set up the connection to the **IDF** tool. **If you have downloaded a different version, please change the version number below**.
         ```
         cd C:\Espressif\frameworks\esp-idf-v5.4.3
         ```
      - We want to wake up the esp-idf tool, but the windows security blocks them. So, to allow temporarily access to terminal, please run the code below. 
         ```
         Set-ExecutionPolicy -ExecutionPolicy Bypass -Scope Process
         ```
      - After allowing temporary access to the terminal, we want to wake up the IDF tool, run the command below.
         ```
         & .\export.ps1
         ```
   3. To make sure you have the correct version ( for my case: v5.4.3)
      ```
      idf.py --version
      ```
<p align="left">
<img width="327" height="49" alt="image" src="https://github.com/user-attachments/assets/fa19a9d1-3199-4ff6-bb10-5936480e5020" />
</p>

> [!TIP]
> If you have trouble running the idf.py command, repeat section 4.

> [!NOTE]
>AT THIS POINT, YOU HAVE CONNECTED TO IDF TOOL AND ARE READY TO COMPILE AND RUN YOUR CODE. Next, navigate to your main code source file.
## 4. HOW TO BUILD AND FLASH YOUR CODE FROM POWERSHELL
   - Go to your project if you have one. If not, you can run example codes from ESP-IDF folder. Search the PATH below in your file Explorer, the choose you example code. Open in you VS.\
      if you have downloaded in C drive:
       ```
      C:\Espressif\frameworks\esp-idf-v5.5.1-2\examples\get-started
       ```
   - Make sure target set to your target device (my target is esp32p4). If not, run:
       ```
       idf.py set-target esp32p4
       ```
   - (*) If you have build the project before, clean before flash (it will remove old build folder), run:
       ```
       idf.py fullclean
       ```
   - Then build:
       ```
       idf.py build
       ```
   - Then to flash it to your device and display a monitor, run the command below. (Instead of x put the COM number).
       ```
       idf.py -p COMx flash monitor
       ```
   - To run seperate flash and monitor command here they are:
      ```
      idf.py -p COMx flash
      ```
      To opem a monitor:
      ```
      idf.py monitor 
      ```
   - To exit the terminal click --> **Ctrl[+]**

## TIPS FOR DEBUGGING ESP SET UP:
- Python Virtual Environment
- If you have a problem with running idf.py command or if your terminal can't recognize, go to section 4 and repeat the bridge conncetion steps.
- If you have chnaged your path or downloaded new things, please close the PowerShell window and open a new one again. 
> [!NOTE]
> At this point you have successfully done with setting up ES_IDF tool and learned how to set up the bridge bewteen the powershell and IDF tool. You also learned how to flash and compile as well. Documnets below shows how to set up other application of ESP set ups.
# ESP-IDF Bluetooth Setup Instruction For Start Up
Assumed: You have an working file of codes that u want to run on your machine. 
## What to change in your given code:
In your code: Look for idf_Something.yml file in your main folder. (usually same folder as the main.c).\
Then you will see it is starts with **dependencies**:\
Look for a line: 
   ```
   nimble_peripheral_utils:
   path: XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
   ```
- Then go to your Espressif folder and look for where is your nimble_peripheral_utils file is located in your folder.
- And copy that path. But here I have copied the path below with a different version of ESP_IDFs; you can copy and paste it.\
   **Remember to change the C:\ if you didn't downloaded in your C drive**.

   - Version of ESP_IDF: **esp-idf-v5.5.1-2**.
      ```
      C:\Espressif\frameworks\esp-idf-v5.5.1-2\examples\bluetooth\nimble\common\nimble_peripheral_utils
      ```
    - Version of ESP_IDF: **esp-idf-v5.4.3**.
      ```
      C:\Espressif\frameworks\esp-idf-v5.4.3\examples\bluetooth\nimble\common\nimble_peripheral_utils
      ```
## What to Run in Power Shell Teminal:
   - Repeat Section 4 in ESP-IDF Set up: Link to the section 4 [Link Text](#bridge-connecting-betweem-powershell-and-idf-tool).
   - ink to the sample section: [Link Text](#sample-section).

## How to run your code
- Please go to your main code file folder in power shell.
```
cd C:\Users\...
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








   
