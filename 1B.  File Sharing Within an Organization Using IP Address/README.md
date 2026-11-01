# Experiment 1B – File Sharing Within an Organization Using IP Address

## Aim
File sharing within an organization using an IP address.

## Theory
In a local area network (LAN), computers communicate using unique numeric identifiers called **IP (Internet Protocol) addresses**. File sharing within an organization relies on the **Server Message Block (SMB)** protocol over TCP/IP, which allows client applications to read and write files on a host server.

## Tools Required
- Two Windows PCs on the same LAN/subnet
- Command Prompt

## Procedure

### 1. Host network identification
Retrieve the host IP address and adapter details:
```
ipconfig
```


### 2. Network connectivity verification
Verify connectivity and latency using ICMP echo requests:
```
ping 10.17.106.178
```


### 3. Directory sharing configuration
On the host machine, right-click the folder → **Properties → Sharing → Advanced Sharing** → tick **Share this folder** → **Permissions** → allow Read/Change/Full Control for the required users.



### 4. Remote access via UNC path
From a client machine on the same subnet (255.255.255.0), press `Win + R` and enter:
```
\\10.17.106.178\Shared_Folder
```


## Result
The shared folder was accessible from the client machine using the host's IP address.

## Conclusion
Network interface configuration was retrieved using `ipconfig`, IP connectivity was verified using `ping` with 0% packet loss, and file sharing within the organization was established using the host's IP address.
