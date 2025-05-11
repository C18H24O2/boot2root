# Writeup 4 - Apache suEXEC

> This writeup takes from [Writeup 1](../writeup1/README.md), having discovered `phpmyadmin` credentials.

This is a small trick we can use to read files via PHP using a vulnerability in Apache 2.2.22 and below. This is especially useful when PHP code is restricted and functions such as `system` are not available.

