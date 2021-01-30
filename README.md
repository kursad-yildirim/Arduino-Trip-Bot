# Arduino-Trip-Bot
Trip-Bot is an Arduino Uno R3 based robot car. It has equipped with sensors, bluetooth and remote control (over bluetooth).

<h1>Trip-Bot</h1>
<h2>Hardware</h2>
    <p>
        <b><u>ARDUINO</u></b><br>
        <a target="_blank" href="https://www.amazon.com/ELEGOO-Board-ATmega328P-ATMEGA16U2-Compliant/dp/B01EWOE0UU/ref=sr_1_2_sspa?dchild=1&keywords=arduino+uno&qid=1611699587&sr=8-2-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUExNlNRTzY3RUZENzNVJmVuY3J5cHRlZElkPUEwOTQzOTgwM08wTElUQzg4WUxBUCZlbmNyeXB0ZWRBZElkPUEwNzY1NzM2M0VJQ0VJMTdZNDVHWCZ3aWRnZXROYW1lPXNwX2F0ZiZhY3Rpb249Y2xpY2tSZWRpcmVjdCZkb05vdExvZ0NsaWNrPXRydWU="> Arduino UNO R3 </a><br>
        Original board has been used. Clons should be fine too. 
    </p>
    <p>
        <b><u>BODY</u></b><br>
        <a target="_blank" href="https://www.amazon.com/ALLPARTZ-Aluminum-Educational-Robotics-Engineering/dp/B07LCHPQ9G/ref=sr_1_80?crid=3327LULUMAFWB&dchild=1&keywords=2wd%2Brobot%2Bchassis&qid=1611698062&sprefix=2wd%2Brobot%2B%2Caps%2C311&sr=8-80&th=1"> 2WD Aluminium Robot Chasis </a><br>
        Chasis comes with two DC Motors. Any other chasis can be used. The given here is to control to DC motors. 
    </p>
    <p>
        <b><u>SENSORS</u></b><br>
        <a target="_blank" href="https://www.amazon.com/SainSmart-HC-SR04-Ranging-Detector-Distance/dp/B004U8TOE6/ref=sr_1_8?crid=CJP1YF8JKMDV&dchild=1&keywords=hc-sr04&qid=1611698562&sprefix=hc-sr%2Caps%2C291&sr=8-8"> HC-SRO4 Ultrasonic Sensor</a><br>
        A very good and affordable ultrasonic sensor. It uses 4 pins. VCC, GND, TRIG, and ECHO. So it consumes two pins from Arduino. Groove Ultrasonic Sensor is a nice replacement. It uses same pin for both Trigger and Echo and saves one pin from Arduino.<br>
        <a target="_blank" href="https://www.electroschematics.com/motor-speed-sensor-module-circuit/"> Motor Speed Sensor</a><br>
    </p>
    <p>
        <b><u>ARDUINO SHIELDS</u></b><br>
        Three Arduino shields have been stacked:<br>
        <a target="_blank" href="https://wiki.seeedstudio.com/Base_Shield_V2/"> Sensor Shield</a><br>
        Instead of using a base shield you can go with direct cabling between sensors and Arduino. Using a base shield will decrease the cabling mess at a considerable amount.<br>
        <a target="_blank" href="https://wiki.seeedstudio.com/Base_Shield_V2/"> Motor Shield</a><br>
        Theoritically any motor shield which can drive two DC motors can be used. This specific one is used because it allows other shields to be stacked on top of it.<br>
        <a target="_blank" href="https://wiki.seeedstudio.com/Bluetooth_Shield_V2/"> Bluetooth Shield</a><br>
        Selected bluetooth shield can be used as both Master and Slave.<br>
    </p>
        <p>
        <b><u>Other</u></b><br>
        <ul>
            <li>Lipo Battery</li>
            <li>Jumper Cables</li>
            <li>On/Off Switch</li>
        </ul>
    </p>

<h1>Trip-Controller</h1>
