Invoke-WebRequest 'https://github.com/tModLoader/tModLoader/releases/latest/download/tModLoader.zip' -OutFile $env:TEMP\tModLoader.zip
Expand-Archive -Path $env:TEMP\tModLoader.zip -DestinationPath ../tModLoader -Force
pause
