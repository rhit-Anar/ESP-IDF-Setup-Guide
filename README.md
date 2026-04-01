# ESP-IDF Setup Guide
This documentation will help how to set ESP-IDF on you computer without requiring any pre knowledge. An easy step-by-step steup.
## Make sure you have these downloaded on your computer:
-Python 3.11. Link: https://www.python.org/ftp/python/3.11.7/python-3.11.7-amd64.exe 
-Install VS code: usually it is downloaded. 
## Downloading ESP_IDF:
1. Download EDP-IDF Tools 5.4.3 version because EDP-IDF doesn’t support version below that. Click on the link: [ Download ESP-IDF 5.4.3 make sure to click the correct version ](https://dl.espressif.com/dl/esp-idf/?idf=4.4)
2. Make sure to download the folder you desire. For this case, I downloaded it in C drive.
3. After downloading you would see path like: C:\Espressif\frameworks\esp-idf-v5.4.3
4. I recommend doing everything in Windows PowerShell because it is easier than doing it in the ESP-IDF terminal.
5. Make sure you have export.ps1 in your path such as: C:\Espressif\frameworks\esp-idf-v5.4.3 => export.ps1.  
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
6. To make sure you have v5.4.3 run:
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



   
