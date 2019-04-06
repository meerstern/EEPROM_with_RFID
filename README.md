# EEPROM_with_RFID
Grove extension board of M24SR64.

[デュアルインタフェースEEPROM M24SR64][1]とアンテナを搭載したI2C Groveモジュールです。  
EEPROMにI2CとRFIDの2つの通信で内部のデータにアクセスできます。  
RFIDの通信の場合はEEPROMに電源を供給せずともRFIDの電波でそのままパッシブにEEPROMが動作します。  

一般的なEEPROMと異なり、NDEF(NFC Data Exchange Format)方式でEEPROMにデータを書き込む必要があります。  
一般的なEEPROMの様にバイト、ページ単位での書き込みには対応していません。  
NDEF(NFC Data Exchange Format)方式で書き込むためには数10kバイト以上のRAMメモリ領域が必要です。  
そのため、ArduinoUNO、PIC、F3以下のSTM32マイコン等での動作保証はできません。  
URLを書き込むSTM32F401のサンプルコードを用意しています。  

[EEPROM M24SR64][1]はISO 14443 NFC/RFID tag NFC forum Type 4 に対応しており、Felicaと同等規格です。
  
なお、NFCリーダ/ライタはNFCタグやNFCカードを駆動させる電波を発するため技適が必要ですが、  
本モジュールはパッシブ(NFCタグやNFCカード側)のため、技適は不要です。  

 <img src="https://github.com/meerstern/EEPROM_with_RFID/blob/master/img1.jpg" width="360">
 <img src="https://github.com/meerstern/EEPROM_with_RFID/blob/master/img2.jpg" width="360">
 
  <img src="https://github.com/meerstern/EEPROM_with_RFID/blob/master/photo1.JPG" width="360">
 <img src="https://github.com/meerstern/EEPROM_with_RFID/blob/master/photo2.JPG" width="360">
 
[1]: https://www.st.com/ja/nfc/m24sr64-y.html "*1"

License - MIT
