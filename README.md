# rosdummy

placeholder roborio code when running ros on the jetson fulltime

## things this does:

- initializes all CAN rev devices (to let the jetson use them instead, super weird workaround)

## things this will do eventually:

- tell the jetson what mode the robot is in + other DS/FMS related things like alliance color
- if needed, passthru controller info but id prefer just having direct comms from DS laptop to ros