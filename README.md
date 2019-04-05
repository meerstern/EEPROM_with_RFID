# EEPROM_with_RFID
Grove extension board of M24SR64.



[デュアルインタフェースEEPROM M24SR64][1]とアンテナを搭載したI2C Groveモジュールです。  
EEPROMにI2CとRFIDの2つの通信で内部のデータにアクセスできます。  
RFIDの通信の場合はEEPROMに電源を供給せずともRFIDの電波でそのままパッシブにEEPROMが動作します。  
RFIDの電波でパッシブで動作するため、マイコンの電源を入れなくともデータの読み書きができます。  
[EEPROM M24SR64][1]はISO 14443 NFC/RFID tag NFC forum Type 4 に対応しており、Felicaと同等規格です。
  
なお、NFCリーダ/ライタはNFCタグやNFCカードを駆動させる電波を発するため、技適が必要ですが、
本モジュールはパッシブ(NFCタグやNFCカード側)のため、技適は不要です。

 <img src="https://github.com/meerstern/EEPROM_with_RFID/blob/master/img1.jpg" width="360">
 <img src="https://github.com/meerstern/EEPROM_with_RFID/blob/master/img2.jpg" width="360">
 
[1]: https://www.st.com/ja/nfc/m24sr64-y.html "*1"

License - MIT
