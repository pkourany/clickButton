ClickButton
===========
- Jan 2016, update to Libraries 2.0

A library that decodes multiple clicks on one button. Also copes with 
long clicks and click-and-hold. 
 
Usage:
-------

```
ClickButton buttonObject(pin [LOW/HIGH, [CLICKBTN_PULLUP]]);
```
 
where LOW/HIGH denotes active LOW or HIGH button (default is LOW) 
CLICKBTN_PULLUP is only possible with active low buttons. 
 
Returned click counts:
----------------------

   A positive number denotes the number of (short) clicks after a released button
   A negative number denotes the number of "long" clicks

