'use strict';

const assert = require('assert');

const monoclock = require('./index');

function isMonotonicStep(left, right) {
  if (left.sec < right.sec) {
    return true;
  }
  if (left.sec === right.sec) {
    if (left.msec < right.msec) {
      return true;
    }
    if (left.msec === right.msec) {
      if (left.usec < right.usec) {
        return true;
      }
      if (left.usec === right.usec) {
        if (left.nsec < right.nsec) {
          return true;
        }
      }
    }
  }
  return false;
}

let prev = monoclock.getTime();
for (let i = 0; i < 100; i++) {
  const time = monoclock.getTime();
  console.log(time);
  assert(isMonotonicStep(prev, time), `non-monotonic step between ${JSON.stringify(prev)} and ${JSON.stringify(time)}`);
  prev = time;
}
