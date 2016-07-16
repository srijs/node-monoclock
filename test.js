'use strict';

const monoclock = require('./index');

for (let i = 0; i < 100; i++) {
  console.log(monoclock.getTime());
}
