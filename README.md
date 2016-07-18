# Cross-platform Monotonic Clock [![CircleCI](https://circleci.com/gh/srijs/node-monoclock.svg?style=svg)](https://circleci.com/gh/srijs/node-monoclock) [![Build status](https://ci.appveyor.com/api/projects/status/dapkmqm7u1b11vgl?svg=true)](https://ci.appveyor.com/project/srijs/node-monoclock)

## About

MonoClock provides a monotonic and steady clock for a variety of platforms, including Linux, OS X and Windows.

It provides two guarantees about that clock:

- It progresses monotonically, which means the value of the clock will only increase between two calls, and never decrease.
- It progresses steadily, which means that every tick takes the same amount of time (in terms of physical time).

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
