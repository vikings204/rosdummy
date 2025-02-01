# rosdummy

placeholder roborio code when running ros on the jetson fulltime

## things this does:

- initializes all CAN rev devices (to let the jetson use them instead, super weird workaround)
- tells the jetson what mode the robot is in + other DS/FMS related things like alliance color
- passthru controller info (until replaced by direct DS laptop to jetson thing)

## things this will do eventually:

- be tested and confirmed working