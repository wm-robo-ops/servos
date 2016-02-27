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
gcc -Wall -pthread -o setPos setPos.c -lpigpiod_if2 -lrt
./setPos pan_ang tilt_ang
```
