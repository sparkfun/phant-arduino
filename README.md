# phant-arduino

The goal of this library is to provide a simple interface for logging data to phant.
It will eventually take any data type, convert it to a `String`, and build a url. This
library will not handle interaction with WiFi or ethernet shields, it's only goal is
to make it easier for users to build URLs.

## Installation

```bash
$ cd ~
$ git clone git@github.com:sparkfun/phant-arduino.git
$ ln -s ~/phant-arduino/Phant/ ~/Document/Arduino/libraries/Phant
```

## Example

```ino

#include <Phant.h>

// Arduino example stream
// host, public key, private key
Phant phant("http://data.sparkfun.com/", "VGb2Y1jD4VIxjX3x196z", "9YBaDk6yeMtNErDNq4YM");

void setup() {
  Serial.begin(9600);
}

void loop() {

  phant.add("val1", "testing");
  phant.add("val2", 12);
  phant.add("val3", 0x65);

  Serial.println(phant.url());

  delay(2000);

}

```
