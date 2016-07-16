'use strict';

const addon = require('./build/Release/addon');

exports.getTime = function () {
  return addon.getTime();
};
