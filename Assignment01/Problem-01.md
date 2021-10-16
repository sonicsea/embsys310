### Device: **GPS**

### How System Works:
* Connect to provider's server via WiFi to download/update data map on device, and store in ROM
* Process map data to render visible UI on the device
* Connect to satellite :satellite: to retrieve device's location data, such as latittude/longitude. Store in RAM
* Use the satellite data and the map data to render the device's location on the visual map
* Maintain connection to satellite to keep refreshing location data in real time
* Device can store list of addresses in ROM
* Store algorithms that calculate the route between current location and destination

### Design Challenges:
* Throughput: process satellite data and local map data to keep refreshing the UI
* Response: calculate a new route as fast as possible in case the user misses a turn
* Reliability: "Am I really at what it says I am at?", "Is this really the shortest route to Disneyland?", "Is this route really toll free?"
* Memory Space: with limited memory, how much map data can it store? What's the best way to store the data on ROM?
* Power consumption: software should help converve power
* Program Installation and upgrade: use WiFi to download latest map data. Or download data to a PC and connect the device to the PC via USB in order to get the latest data.
* Connection: secure connection to the satellite