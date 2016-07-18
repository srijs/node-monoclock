# Cross-platform Monotonic Clock [![CircleCI](https://circleci.com/gh/srijs/node-monoclock.svg?style=svg)](https://circleci.com/gh/srijs/node-monoclock) [![Build status](https://ci.appveyor.com/api/projects/status/dapkmqm7u1b11vgl?svg=true)](https://ci.appveyor.com/project/srijs/node-monoclock)

> Supported on Linux, OS X and Windows

## Installation

```
npm install monoclock
```

## Usage

```
import * as monoclock from 'monoclock';

monoclock.getTime();
// { sec: 20243, nsec: 723136835 }
```
