# 5GNR_modem_SDR
This is a physical layer full simulation based on C-code from gNodeB to NR-ue.
(All the algorithm Libs are implemented by C codes. the GUI is implemented with MFC. the release version will be upload in succession)

current finished:
1. gNB transmit DL physical channel, including PDCCH and PDSCH, PDCCH DMRS, PDSCH DMRS, SSB, CSI-RS.
2. NR-UE receive the DL physical channel, including SSB/PDCCH/PDSCH and corresponding DMRS. 
3. UE Channel estimation, EQualization, Demodulation and Decode.
......
finished sub-function:
1. polar encoding, LPDC encoding
2. polar decoding, LPDC decoding
3. channel interleaving, modulation, demodulation
.....

next development module:
1. NR-UE UL transmite
2. gNB UL receive.

The demo exe are placed in x64/win32, if you can not compile/link pass, please use the exe. 

2020.5.22
增加将gNb的资源Grid以RB和RE两种颗粒度输出为excel文件的形式，方便debug，了解当前资源分布情况
![Image](https://github.com/wirelessModem/wirelessModem.github.io/blob/master/NbTxViewRBGrid.png?raw=true)

//
This is a open source project, please do not use it to any commercial project. 
If you are interested and expected get all libs' source codes, please contact with me.
my permanent email: calmet@qq.com
weixin QR code:

![Image](https://github.com/wirelessModem/wirelessModem.github.io/blob/master/weixin.png?raw=true)

Go==>[5GNR_modem_SDR@github](https://github.com/wirelessModem/wirelessModem.github.io)
