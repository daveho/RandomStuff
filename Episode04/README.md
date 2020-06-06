# Episode 2: 

Link to video: <https://youtu.be/xyFBnrxw_VE>

I made this video to document the hardware and software setup I use to making videos using Linux.  This page has links to the hardware and software mentioned in the video, as well as a few additional items.

Note that I have no affiliation with any products or manufacturers mentioned here.  I'm linking to Amazon for reference purposes, but feel free to buy things by whatever means you feel most comfortable with.  (These are not affiliate links.)

## Hardware

HDMI capture: [Blackmagic Intensity Pro 4K](https://www.amazon.com/Blackmagic-Design-Intensity-Capture-Playback/dp/B00U3QNP7Q); note that you will need to download and install the (closed source) drivers

Camera: [Canon Vixia HF R600](https://www.amazon.com/Canon-VIXIA-Black-Discontinued-Manufacturer/dp/B00RKNO06K); I also have an R400, which works well, and I believe any of the models starting with the R200 are largely equivalent.

Microphone: [Fifine USB microphone K669B](https://www.amazon.com/Microphone-Condenser-Recording-Streaming-669B/dp/B06XCKGLTP)

Some miscellaneous items I didn't mention explicitly:

[Magic arm camera mount](https://www.amazon.com/pangshi-Adjustable-Articulating-Friction-Compatible/dp/B06VYCVVVJ): I use this as the permanent camera mount above my desk

[Smatree clamp mount](https://www.amazon.com/Smatree-Ajustable-Gooseneck-Extension-Session/dp/B00MWNYGUS): these are handy for mounting lighting

[Mini HDMI to HDMI cable](https://www.amazon.com/Cable-Rankie-High-Speed-Mini-HDMI-Black/dp/B01KRKO4MM): you'll need this to connect the camera to the HDMI capture card

## Software

Video editing: [kdenlive](https://kdenlive.org/en/); I just use the version that is available from the Ubuntu 18.04 package repository

Video capture: [OBS Studio](https://obsproject.com/); I use the version from the PPA, see the [Install Directions](https://obsproject.com/wiki/install-instructions#linux)

Note that to do GPU-accelerated video encoding, you need to have a VAAPI driver.  The one I'm using, which is for the integrated GPU in my CPU (Core i7-4771), can be installed on Ubuntu 18.04 as follows:

```
sudo apt-get install i965-va-driver-shaders
```

Screencasting: [Kazam](https://launchpad.net/kazam); I'm just using the default version from the Ubuntu 18.04 repositories

Graphics editing (for titles and overlays): [Gimp](https://www.gimp.org/); again, just the default Ubuntu 18.04 version

Audio recording: [Audio Recorder](https://launchpad.net/audio-recorder); install from the PPA, <https://launchpad.net/~audio-recorder/+archive/ubuntu/ppa>
