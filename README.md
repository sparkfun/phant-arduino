# phant-arduino

The goal of this library is to provide a simple interface for logging data to phant.
It will eventually take any data type, convert it to a `String`, and build a url. This
library will not handle interaction with WiFi or ethernet shields, it's only purpose is
to make it easier for users to build phant compatible requests without worrying about data
types and string concatenation.

## Installation

**Linux & Mac:**
```bash
$ cd ~
$ git clone git@github.com:sparkfun/phant-arduino.git
$ ln -s ~/phant-arduino/Phant/ ~/Documents/Arduino/libraries/Phant
```

**Windows:** :cry:

## Example

```ino
#include <Phant.h>

// Arduino example stream
// http://data.sparkfun.com/streams/VGb2Y1jD4VIxjX3x196z
// host, public key, private key
Phant phant("data.sparkfun.com", "VGb2Y1jD4VIxjX3x196z", "9YBaDk6yeMtNErDNq4YM");

void setup() {
  Serial.begin(9600);
}

void loop() {

  phant.add("val1", "url");
  phant.add("val2", 22);
  phant.add("val3", 0.1234);

  Serial.println("----URL-----");
  Serial.println(phant.url());

  Serial.println();

  phant.add("val1", "get");
  phant.add("val2", true);
  phant.add("val3", 0x65);

  Serial.println("----HTTP GET----");
  Serial.println(phant.get());

  Serial.println();

  phant.add("val1", "post");
  phant.add("val2", false);
  phant.add("val3", 98.6);

  Serial.println("----HTTP POST----");
  Serial.println(phant.post());

  Serial.println();

  delay(2000);

}
```

This example prints the following to the serial monitor:

```
----URL-----
http://data.sparkfun.com/input/VGb2Y1jD4VIxjX3x196z?private_key=9YBaDk6yeMtNErDNq4YM&val1=url&val2=22&val3=0.1234

----HTTP GET----
GET /input/VGb2Y1jD4VIxjX3x196z?private_key=9YBaDk6yeMtNErDNq4YM&val1=get&val2=1&val3=101 HTTP/1.1
Host: data.sparkfun.com
Connection: close


----HTTP POST----
POST /input/VGb2Y1jD4VIxjX3x196z HTTP/1.1
Host: data.sparkfun.com
Connection: close
Content-Type: application/x-www-form-urlencoded
Content-Length: 29

val1=post&val2=0&val3=98.6000
```
