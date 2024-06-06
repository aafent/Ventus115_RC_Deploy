! ==============================================================================
! = - INCLUDE SQR LIBRARY : graph.inc
! = ----------------------------------------------------------------------------
! = - PROCEDURES          : drawbow, 
! = -                       drawline
! ==============================================================================

begin-procedure drawbox (#y1, #x1, #y2, #x2, $c1, $c2, $c3)

  let #z = #x2 - #x1

  print $c1 (#y1, #x1, #z) fill
  print $c1 (#y2, #x1, #z) fill

  let #z   = #y2 - #y1
  let #inx = 1

  while #inx < #z

    let #y = #inx + #y1

    print $c2 (#y, #x1, 1)
    print $c2 (#y, #x2, 1)

    let #inx = #inx + 1

  end-while

  print $c3  (#y2, #x2, 1)
  print $c3  (#y2, #x1, 1)
  print $c3  (#y1, #x2, 1)
  print $c3  (#y1, #x1, 1)

end-procedure

! ------------------------------------------------------------------------------

begin-procedure drawline (#y1, #y2, #x1, $c1, $c2)

  let #z   = #y2 - #y1
  let #inx = 1

  while #inx < #z

    let #y = #inx + #y1

    print $c1 (#y, #x1, 1)

    let #inx = #inx + 1

  end-while

  print $c2  (#y2, #x1, 1)
  print $c2  (#y1, #x1, 1)

end-procedure
