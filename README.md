# servos

## Dependencies
pigpio

## Installing

### PIGPIO

```
wget abyz.co.uk/rpi/pigpio/pigpio.zip
unzip pigpio.zip
cd PIGPIO
make
sudo make install
```

## Running

```
sudo pigpiod
make
./setPos pan_ang tilt_ang
```
