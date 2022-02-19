# RX8 Instrument Cluster - CAN Bus Protocol
The Mazda RX8 utilises a high-speed CAN bus for communicating between the various modules found throughout the vehicle, with each module constantly transmitting and receiving
packets of data containing variables relevant to its operation. The following table contains a list of CAN bus messages that are required in the operation of the RX8s
instrument cluster, each being of standard frame size and transmitted onto the bus at a speed of 500 kBit per second.

| ID         | Size (Bytes) | Module  | Contents
| ---------- | :----------: | ------- | --------
| 0x420      | 7            | PCM     | Coolant Temperature & Warning Lights
| 0x201      | 8            | PCM     | Vehicle Speed & Engine RPM
| 0x650      | 1            | PCM     | Cruise Control lights 
| 0x231      | 2            | TCM     | Gear display, AT warning light
| 0x300      | 1            | EPS     | Power steering warning light
| 0x212      | 6            | ABS/DSC | Brake warning light, DSC OFF light, DSC light, ABS light

### Module Acronyms
**PCM** - Powertrain Control Module</br>
**TCM** - Transmission Control Module</br>
**EPS** - Electronic Power Steering</br>
**ABS** - Anti-lock Braking System</br>
**DSC** - Dynamic Stability Control</br>

## CAN Bus Message Layouts
<details>
    <summary>Message 0x420 - Coolant Temperature & Warning Lights</summary>
    <br><b>Coolant Temperature & Warning Lights</b>
    <p>This message, originating from the PCM, is responsible for initialising the cluster, allowing for the engine-related warning lights to be cleared and the engine
        coolant temperature to be displayed on the gauge. If the cluster doesn't receive this message at least once every couple of seconds, 
        then all of the warning lights will default to being illuminated and the needles of the oil pressure/coolant temperature gauges will sit
        far to the left, off the face of the gauge itself.</p>
    <b>Message Layout</b>
    <table>
        <thead>
            <tr>
                <th>Byte</th>
                <th>Bit 7</th>
                <th>Bit 6</th>
                <th>Bit 5</th>
                <th>Bit 4</th>
                <th>Bit 3</th>
                <th>Bit 2</th>
                <th>Bit 1</th>
                <th>Bit 0</th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td align="center"><b>0</b></td>
                <td colspan="8" align="center"><b>Coolant Temperature</td>
            </tr>
            <tr>
                <td align="center"><b>1</b></td>
                <td colspan="8" align="center"><span color="gray">N/A</span></td>
            </tr>
            <tr>
                <td align="center"><b>2</b></td>
                <td colspan="8" align="center"><span color="gray">N/A</span></td>
            </tr>
            <tr>
                <td align="center"><b>3</b></td>
                <td colspan="8" align="center"><span color="gray">N/A</span></td>
            </tr>
            <tr>
                <td align="center"><b>4</b></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><code>OilP</code></td>
            </tr>
            <tr>
                <td align="center"><b>5</b></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><code>CEL</code></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
            </tr>
            <tr>
                <td align="center"><b>6</b></td>
                <td align="center"><code>OilL</code></td>
                <td align="center"><code>Batt</code></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><code>ECL</code></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
            </tr>
        </tbody>
    </table>
    <h4>Flag Descriptions</h4>
    <table>
        <thead>
            <tr>
                <th>Light</th>
                <th>Flag</th>
                <th>Name</th>
                <th>Description</th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td></td>
                <td><code>OilP</code></td>
                <td>Oil Pressure</td>
                <td>The RX8 is equipped with an engine oil pressure gauge, however the resolution is only a single bit. This makes it a dummy gauge, 
                    with the needle pointing to L (low) when the bit is set to 0, and to the centre of the gauge when it is set to 1</td>
            </tr>
            <tr>
                <td><img src="./icons/cel.png?raw=true" width="32" height="32"/></td>
                <td><code>CEL</code></td>
                <td>Check Engine Light</td>
                <td>Illuminates the Check Engine Light when set to 1</td>
            </tr>
            <tr>
                <td><img src="./icons/oilL.png?raw=true" width="32" height="32"</td>
                <td><code>OilL</code></td>
                <td>Oil Level Light</td>
                <td>Illuminates the oil level warning light when set to 1</td>
            </tr>
            <tr>
                <td><img src="./icons/batt.png?raw=true" width="32" height="32"</td>
                <td><code>Bat</code></td>
                <td>Battery Voltage Light</td>
                <td>Illuminates the battery/electrical system warning light when set to 1</td>
            </tr>
            <tr>
                <td><img src="./icons/ecl.png?raw=true" width="32" height="32"</td>
                <td><code>ECL</code></td>
                <td>Engine Coolant Level</td>
                <td>Illuminates the battery/electrical system warning light when set to 1</td>
            </tr>
        </tbody>
    </table>
</details>
<details>
    <summary>Message 0x201 - Vehicle Speed & Engine RPM</summary>
    <br><b>Vehicle Speed & Engine RPM</b>
    <p>
        This message, also originating from the PCB, broadcasts both the engine speed (RPM) and the vehicle speed, which is likely being fed to the PCM from
        the sensor on the extension housing of the transmission. The values accepted by the cluster for the vehicle speed and RPM aren't 1:1, and require scaling
        and sometimes an offset.<br><br>
        For example, the expected vehicle speed is in km/h, but with an offset value of 100.0 and a scale of 100.0
        <br><code class="language-cpp">(kmh + 100.0) * 100.0</code><br>
    </p>
    <b>Message Layout</b>
    <table>
        <thead>
            <tr>
                <th>Byte</th>
                <th>Bit 7</th>
                <th>Bit 6</th>
                <th>Bit 5</th>
                <th>Bit 4</th>
                <th>Bit 3</th>
                <th>Bit 2</th>
                <th>Bit 1</th>
                <th>Bit 0</th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td align="center"><b>0</b></td>
                <td colspan="8" rowspan="2" align="center"><b>Engine RPM</b><br><span color="green">rpm</span> * 3.85</td>
            </tr>
            <tr>
                <td align="center"><b>1</b></td>
            </tr>
            <tr>
                <td align="center"><b>2</b></td>
                <td colspan="8" align="center"><span color="gray">N/A</span></td>
            </tr>
            <tr>
                <td align="center"><b>3</b></td>
                <td colspan="8" align="center"><span color="gray">N/A</span></td>
            </tr>
            <tr>
                <td align="center"><b>4</b></td>
                <td colspan="8" rowspan="2" align="center"><b>Vehicle Speed</b><br>(<span color="green">km/h</span> + 100.0) * 100.0</td>
            </tr>
            <tr><td align="center"><b>5</b></td></tr>
            <tr>
                <td align="center"><b>6</b></td>
                <td colspan="8" align="center"><span color="gray">N/A</span></td>
            </tr>
            <tr>
                <td align="center"><b>7</b></td>
                <td colspan="8" align="center"><span color="gray">N/A</span></td>
            </tr>
        </tbody>
    </table>
</details>
<details>
    <summary>Message 0x650 - Cruise Control</summary>
    <br><br>
    <b>Message Layout</b>
    <table>
        <thead>
            <tr>
                <th>Byte</th>
                <th>Bit 7</th>
                <th>Bit 6</th>
                <th>Bit 5</th>
                <th>Bit 4</th>
                <th>Bit 3</th>
                <th>Bit 2</th>
                <th>Bit 1</th>
                <th>Bit 0</th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td align="center"><b>0</b></td>
                <td align="center"><code>CCM</code></td>
                <td align="center"><code>CC</code></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
            </tr>
        </tbody>
    </table>
</details>
<details>
    <summary>Message 0x231 - Shift Position Indicator</summary>
    <br>This message comes from the TCM (Transmission Control Module) and is used by the instrument cluster on <b>automatic transmission models</b> to
    display the current shifter position, or the currently selected gear if the transmission has been placed into manual mode.
    <br><br>
    <b>Message Layout</b>
    <table>
        <thead>
            <tr>
                <th>Byte</th>
                <th>Bit 7</th>
                <th>Bit 6</th>
                <th>Bit 5</th>
                <th>Bit 4</th>
                <th>Bit 3</th>
                <th>Bit 2</th>
                <th>Bit 1</th>
                <th>Bit 0</th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td align="center"><b>0</b></td>
                <td align="center" colspan="4"><b>Manual Mode Gear</b><br>First (1) to Sixth (6)</td>
                <td align="center" colspan="4"><b>Shifter Position</b><br>PARK (1) | REVERSE (2) | NEUTRAL (3) | DRIVE (4)</td>
            </tr>
            <tr>
                <td align="center"><b>1</b></td>
                <td align="center"><code>Man</code></td>
                <td align="center"><code>AT</code></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
            </tr>
        </tbody>
    </table>
    <b>Setting the gear position</b>
    <p></p>
</details>
<details>
    <summary>Message 0x300 - Electronic Power Steering</summary>
    <br><br>
    <b>Message Layout</b>
    <table>
        <thead>
            <tr>
                <th>Byte</th>
                <th>Bit 7</th>
                <th>Bit 6</th>
                <th>Bit 5</th>
                <th>Bit 4</th>
                <th>Bit 3</th>
                <th>Bit 2</th>
                <th>Bit 1</th>
                <th>Bit 0</th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td align="center"><b>0</b></td>
                <td align="center"><code>EPS</code></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
            </tr>
        </tbody>
    </table>
    <h4>Flag Descriptions</h4>
    <table>
        <thead>
            <tr>
                <th>Light</th>
                <th>Flag</th>
                <th>Name</th>
                <th>Description</th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td><img src="./icons/eps.png?raw=true" width="32" height="32"/></td>
                <td><code>EPS</code></td>
                <td>Electronic Power Steering Malfunction Light</td>
                <td>Illuminates the EPS malfunction light when set to 1</td>
            </tr>
        </tbody>
    </table>
</details>
<details>
    <summary>Message 0x212 - ABS, Traction Control and Stability Control</summary>
    <br><br>
    <b>Message Layout</b>
    <table>
        <thead>
            <tr>
                <th>Byte</th>
                <th>Bit 7</th>
                <th>Bit 6</th>
                <th>Bit 5</th>
                <th>Bit 4</th>
                <th>Bit 3</th>
                <th>Bit 2</th>
                <th>Bit 1</th>
                <th>Bit 0</th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td align="center"><b>0</b></td>
                <td colspan="8" align="center"><span color="gray">N/A</span></td>
            </tr>
            <tr>
                <td align="center"><b>1</b></td>
                <td colspan="8" align="center"><span color="gray">N/A</span></td>
            </tr>
            <tr>
                <td align="center"><b>2</b></td>
                <td colspan="8" align="center"><span color="gray">N/A</span></td>
            </tr>
            <tr>
                <td align="center"><b>3</b></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><code>DSC</code></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
            </tr>
            <tr>
                <td align="center"><b>4</b></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><code>BSW</code></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><code>ABS</code></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
            </tr>
            <tr>
                <td align="center"><b>5</b></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><code>TCSA</code></td>
                <td align="center"><code>TCSO</code></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
            </tr>
        </tbody>
    </table>
    <h4>Flag Descriptions</h4>
    <table>
        <thead>
            <tr>
                <th>Light</th>
                <th>Flag</th>
                <th>Name</th>
                <th>Description</th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td><img src="./icons/dsc-off.png?raw=true" width="32" height="32"/></td>
                <td><code>DSC</code></td>
                <td>Dynamic Stability Control Off Light</td>
                <td>Illuminates the brake system warning light when set to 1.<br>Curiously the cluster requires this light to be illuminated in
                    order to switch on the TCS light via the <code>TCSA</code> or <code>TCSO</code> flags</td>
            </tr>
             <tr>
                <td><img src="./icons/brakes.png?raw=true" width="32" height="32"/></td>
                <td><code>BSW</code></td>
                <td>Brake System Warning Light</td>
                <td>Illuminates the brake system warning light when set to 1.<br> This light is used to indicate a malfunction in the braking system, as well
                as to indicate that the handbrake is engaged</td>
            </tr>
            <tr>
                <td><img src="./icons/abs.png?raw=true" width="32" height="32"/></td>
                <td><code>ABS</code></td>
                <td>ABS Warning Light</td>
                <td>Illuminates the ABS warning light when set to 1</td>
            </tr>
            <tr>
                <td><img src="./icons/slipflash.gif?raw=true" width="32" height="32"/></td>
                <td><code>TCSA</code></td>
                <td>Traction Control System Active</td>
                <td>Flashes the TCS light when set to 1.<br> In the OEM application, this is used to indicate the TCS is on and is currently active</td>
            </tr>
            <tr>
                <td><img src="./icons/slip.png?raw=true" width="32" height="32"/></td>
                <td><code>TSCO</code></td>
                <td>Traction Control System On Light</td>
                <td>Illuminates the TCS light when set to 1.<br> In the OEM application, this light is briefly illuminated upon switching the TCS on</td>
            </tr>
        </tbody>
    </table>
</details>
