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

String Phant::url() {

  String result = _host + "input/" + _pub + "?private_key=" + _prv + _params;

  _params = "";

  return result;

}
