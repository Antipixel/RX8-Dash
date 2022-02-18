# RX8 Instrument Cluster - CAN Bus Protocol
The Mazda RX8 utilises a high-speed CAN bus for communicating between the various modules found throughout the vehicle, with each module constantly transmitting and receiving
packets of data containing variables relevant to its operation. The following table contains a list of CAN bus messages that are required in the operation of the RX8s
instrument cluster, each being of standard frame size and transmitted onto the bus at a speed of 500 kBit per second.

| ID         | Size (Bytes) | Module  | Contents
| ---------- | :----------: | ------- | --------
| 0x420      | 7            | PCM     | Coolant Temperature, Warning Lights
| 0x201      | 8            | PCM     | Vehicle Speed & Engine RPM
| 0x650      | 1            | PCM     | Cruise Control lights 
| 0x231      | 2            | TCM     | Gear display, AT warning light
| 0x300      | 8            | EPS     | Power steering warning light
| 0x212      | 6            | ABS/DSC | Brake warning light, DSC OFF light, DSC light, ABS light

### Module Acronyms
**PCM** - Powertrain Control Module</br>
**TCM** - Transmission Control Module</br>
**EPS** - Electronic Power Steering</br>
**ABS** - Anti-lock Braking System</br>
**DSC** - Dynamic Stability Control</br>

## CAN Bus Message Layouts
<details>
    <summary>PCM (Powertrain Control Module) Messages</summary>
    <h4>Message 0x420 - Coolant Temperature, Warning Lights</h4>
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
                <td align="center"><span color="green">OilP</span></td>
            </tr>
            <tr>
                <td align="center"><b>5</b></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="green">CEL</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
            </tr>
            <tr>
                <td align="center"><b>6</b></td>
                <td align="center"><span color="green">OilL</span></td>
                <td align="center"><span color="green">Bat</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="green">Hot</span></td>
                <td align="center"><span color="gray">-</span></td>
                <td align="center"><span color="gray">-</span></td>
            </tr>
        </tbody>
    </table>
    <h4>Message 0x201 - Vehicle Speed & Engine RPM</h4>
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
                <td colspan="8" rowspan="2" align="center"><b>Vehicle Speed</b><br>(<span color="green">km/h</span> * 100.0) + 10,000</td>
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
