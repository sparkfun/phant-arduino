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

String Phant::url() {

  String result = _host + "input/" + _pub + "?private_key=" + _prv + _params;

  _params = "";

  return result;

}
