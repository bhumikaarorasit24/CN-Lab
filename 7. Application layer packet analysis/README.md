# Experiment 7 – Application Layer Packet Analysis using Wireshark

## Aim
To analyze Application Layer packets (DNS and HTTP) using Wireshark and understand their structure and working.

## Tools Required
- Wireshark (packet analyzer)
- Internet connection or local DNS/HTTP server
- Browser or command-line tools (`nslookup`, `ping`)

## Procedure

### Part A: DNS packet analysis
1. Start Wireshark and begin capture on the active interface (Wi-Fi/Ethernet).
2. In Command Prompt/Terminal run:
   ```
   nslookup www.google.com
   ```
3. Stop the capture after the response.
4. Apply the filter: `dns`
5. Select the DNS query and observe: Transaction ID, Flags (Query/Response), Query Name, Query Type (A – IPv4).
6. Select the DNS response and observe: resolved IP address, TTL, Answer section.

### Part B: HTTP packet analysis
1. In the browser open `http://example.com` (a plain HTTP site).
2. In Wireshark apply the filter: `http`
3. Observe the HTTP GET request: Method (GET), Host, User-Agent.
4. Observe the HTTP response: Status Code (200 OK), Content-Type (text/html), Content-Length.

## Observations
| Field | DNS Query | DNS Response | HTTP Request | HTTP Response |
|---|---|---|---|---|
| Protocol | UDP | UDP | TCP | TCP |
| Port | 53 | 53 | 80 | 80 |
| Method/Type | Standard Query (A record) | Response | GET / | 200 OK |
| IP / Name | www.google.com | e.g. 142.250.77.68 | example.com | IP of example.com |
| TTL | – | 300 seconds (example) | – | – |
| Content-Type | – | – | – | text/html |

## Output / Screenshots

**Fig 1 – DNS query and response in Wireshark**

![Fig 1](images/exp07_fig1.png)

**Fig 2 – HTTP GET request and 200 OK response**

![Fig 2](images/exp07_fig2.png)

**Fig 3 – Website opened in browser**

![Fig 3](images/exp07_fig3.png)

## Result
Successfully analyzed DNS and HTTP packets using Wireshark. The structure and fields of Application Layer packets were observed and interpreted.

## Conclusion
- DNS resolves domain names to IP addresses via UDP port 53.
- HTTP works over TCP port 80: the client sends a GET request and receives a response with a status and content.
- Wireshark effectively captures and visualizes Application Layer communication for analysis and troubleshooting.
