# Perception Module for ACME Robotics (ENPM 808X Midterm)
[![Build Status](https://travis-ci.org/patnolan33/Midterm_Perception.svg?branch=master)](https://travis-ci.org/patnolan33/Midterm_Perception)
[![Coverage Status](https://coveralls.io/repos/github/patnolan33/Midterm_Perception/badge.svg?branch=master)](https://coveralls.io/github/patnolan33/Midterm_Perception?branch=master)
---

## Overview

Perception Module repository for ACME robotics (ENPM 808X Midterm Project). Build and test with:

- cmake
- googletest


## SIP Process
The SIP Process followed is detailed in a spreadsheet at the following link:
[SIP Process](https://docs.google.com/spreadsheets/d/13Md_3JxLImuFK3fchP6q6-Ba7_WplzxLPu2Yvax6Z-Q/edit?usp=sharing)

## Installation

- Checkout the repo (and submodules)
```
$ git clone --recursive https://github.com/patnolan33/Midterm_Perception.git
```
## Run Project

- Build project using cmake
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```
- Run program
```
$ ./app/shell-app
```
- Run test
```
$ ./test/cpp-test
```
