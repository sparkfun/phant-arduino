/**
 * Phant.cpp
 *
 *             .-.._
 *       __  /`     '.
 *    .-'  `/   (   a \
 *   /      (    \,_   \
 *  /|       '---` |\ =|
 * ` \    /__.-/  /  | |
 *    |  / / \ \  \   \_\  jgs
 *    |__|_|  |_|__\
 *    never   forget.
 *
 * Author: Todd Treece <todd@sparkfun.com>
 *
 * Copyright (c) 2014 SparkFun Electronics.
 * Licensed under the GPL v3 license.
 *
 */

#include "Arduino.h"
#include "Phant.h"

Phant::Phant(String host, String publicKey, String privateKey) {
  _host = host;
  _pub = publicKey;
  _prv = privateKey;
  _params = "";
}

void Phant::add(String field, String data) {

  _params += "&" + field + "=" + data;

}

void Phant::add(String field, char data) {

  _params += "&" + field + "=" + String(data);

}

void Phant::add(String field, int data) {

  _params += "&" + field + "=" + String(data);

}

void Phant::add(String field, byte data) {

  _params += "&" + field + "=" + String(data);

}

void Phant::add(String field, long data) {

  _params += "&" + field + "=" + String(data);

}

void Phant::add(String field, unsigned int data) {

  _params += "&" + field + "=" + String(data);

}

void Phant::add(String field, unsigned long data) {

  _params += "&" + field + "=" + String(data);

}

void Phant::add(String field, double data) {

  char tmp[30];

  dtostrf(data, 1, 4, tmp);

  _params += "&" + field + "=" + String(tmp);

}

void Phant::add(String field, float data) {

  char tmp[30];

  dtostrf(data, 1, 4, tmp);

  _params += "&" + field + "=" + String(tmp);

}

String Phant::queryString() {
  return String(_params);
}

String Phant::url() {

  String result = "http://" + _host + "/input/" + _pub + ".txt";
  result += "?private_key=" + _prv + _params;

  _params = "";

  return result;

}

String Phant::get() {

  String result = "GET /output/" + _pub + ".csv HTTP/1.1\n";
  result += "Host: " + _host + "\n";
  result += "Connection: close\n";

  return result;

}

String Phant::post() {

  String params = _params.substring(1);

  String result = "POST /input/" + _pub + ".txt HTTP/1.1\n";
  result += "Host: " + _host + "\n";
  result += "Phant-Private-Key: " + _prv + "\n";
  result += "Connection: close\n";
  result += "Content-Type: application/x-www-form-urlencoded\n";
  result += "Content-Length: " + String(params.length()) + "\n\n";
  result += params;

  _params = "";

  return result;

}

String Phant::clear() {

  String result = "DELETE /input/" + _pub + ".txt HTTP/1.1\n";
  result += "Host: " + _host + "\n";
  result += "Phant-Private-Key: " + _prv + "\n";
  result += "Connection: close\n";

  return result;

}
