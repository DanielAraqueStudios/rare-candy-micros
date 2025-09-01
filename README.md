# ESP32-S3 Security System

A simple security system implementation using ESP32-S3 with presence sensors and alarm outputs.

## Project Description

This project implements a basic security system that monitors three different areas using presence sensors (buttons/switches) and activates appropriate alarms based on the detected location.

## Hardware Requirements

- ESP32-S3 development board
- 3x Push buttons or presence sensors
- 1x LED (for visual alarm)
- 1x Buzzer (for audible alarm)
- Resistors (220-330Ω for LED, 10kΩ for pull-up if needed)
- Jumper wires
- Breadboard

## Pin Configuration

### Inputs (Sensors)
- **GPIO 16**: ROOF sensor (Techo)
- **GPIO 17**: MAIN DOOR sensor (Puerta Principal)
- **GPIO 18**: PARKING sensor (Parqueadero)

### Outputs (Alarms)
- **GPIO 9**: LED (Visual alarm)
- **GPIO 46**: Buzzer (Audible alarm)

## System Logic

The security system operates with the following rules:

1. **Main Door (GPIO 17)**: When activated → Both LED and Buzzer turn ON
2. **Roof (GPIO 16)**: When activated → Only LED turns ON
3. **Parking (GPIO 18)**: When activated → Only Buzzer turns ON
4. **Multiple sensors**: Alarms combine appropriately
5. **No sensors active**: Both alarms turn OFF

## Circuit Connections

### Sensors (Inputs)
```
ESP32-S3          Sensor/Button
GPIO 16    ----   Roof Sensor
GPIO 17    ----   Door Sensor  
GPIO 18    ----   Parking Sensor
GND        ----   Common Ground
```

### Alarms (Outputs)
```
ESP32-S3          Component
GPIO 9     ----   LED (+ resistor to GND)
GPIO 46    ----   Buzzer (+ to GND)
```

## Features

- Real-time sensor monitoring
- Immediate alarm response
- Serial monitor output for debugging
- Multiple sensor support
- Automatic alarm shutoff when sensors deactivate

## Serial Monitor Output

The system outputs real-time status information:
```
Buttons - Roof: 0, Door: 1, Parking: 0 | Outputs - LED: 1, Buzzer: 1
Buttons - Roof: 1, Door: 0, Parking: 0 | Outputs - LED: 1, Buzzer: 0
Buttons - Roof: 0, Door: 0, Parking: 1 | Outputs - LED: 0, Buzzer: 1
```

## Building and Flashing

### Prerequisites
- ESP-IDF framework installed
- ESP32-S3 drivers configured

### Build Commands
```bash
# Configure the project
idf.py menuconfig

# Build the project
idf.py build

# Flash to ESP32-S3
idf.py flash

# Monitor serial output
idf.py monitor
```

## Code Structure

- **main.c**: Main application code
- **CMakeLists.txt**: Build configuration
- **sdkconfig**: ESP-IDF configuration

## Usage

1. Connect the hardware according to the pin configuration
2. Build and flash the code to ESP32-S3
3. Open serial monitor to view system status
4. Test sensors by pressing buttons/triggering sensors
5. Observe corresponding alarm activations

## Troubleshooting

- **Alarms don't turn off**: Check if sensors are properly connected and returning to LOW state
- **No serial output**: Verify baud rate (115200) and COM port
- **Sensors not detected**: Check GPIO connections and pull-up resistors if needed
- **Build errors**: Ensure ESP-IDF is properly installed and configured

## Author

Professional Engineering Project - ESP32-S3 Development

## License

This project is for educational and demonstration purposes.
