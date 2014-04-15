/**
 * Phant.h
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

#ifndef Phant_h
#define Phant_h

#include "Arduino.h"

class Phant {

  public:
    Phant(String host, String publicKey, String privateKey);
    void add(String field, String data);
    String url();

  private:
    String _pub;
    String _prv;
    String _host;
    String _params;

};

#endif
