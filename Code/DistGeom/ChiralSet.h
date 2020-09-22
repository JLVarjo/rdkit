//
//  Copyright (C) 2004-2008 Greg Landrum and Rational Discovery LLC
//
//   @@ All Rights Reserved @@
//  This file is part of the RDKit.
//  The contents are covered by the terms of the BSD license
//  which is included in the file license.txt, found at the root
//  of the RDKit source tree.
//
#include <RDGeneral/export.h>
#ifndef __RD_CHIRAL_SET_H__
#define __RD_CHIRAL_SET_H__

#include <RDGeneral/Invariant.h>
#include <boost/smart_ptr.hpp>
#include <vector>

namespace DistGeom {

/*! \brief Class used to store a quartet of points and chiral volume bounds on
 *them
 *
 */
class RDKIT_DISTGEOMETRY_EXPORT ChiralSet {
 public:
  unsigned int d_idx0;  // the centroid
  unsigned int d_idx1;
  unsigned int d_idx2;
  unsigned int d_idx3;
  unsigned int d_idx4;
  double d_volumeLowerBound;
  double d_volumeUpperBound;

  ChiralSet(unsigned int pid0, unsigned int pid1, unsigned int pid2,
            unsigned int pid3, unsigned int pid4, double lowerVolBound,
            double upperVolBound)
      : d_idx0(pid0),
        d_idx1(pid1),
        d_idx2(pid2),
        d_idx3(pid3),
        d_idx4(pid4),
        d_volumeLowerBound(lowerVolBound),
        d_volumeUpperBound(upperVolBound) {
    CHECK_INVARIANT(lowerVolBound <= upperVolBound, "Inconsistent bounds\n");
    d_volumeLowerBound = lowerVolBound;
    d_volumeUpperBound = upperVolBound;
  }

  inline double getUpperVolumeBound() const { return d_volumeUpperBound; }

  inline double getLowerVolumeBound() const { return d_volumeLowerBound; }
};

typedef boost::shared_ptr<ChiralSet> ChiralSetPtr;
typedef std::vector<ChiralSetPtr> VECT_CHIRALSET;

/*! \brief Class used to store a quartet of points and their torsion angle
 *them
 *
 */

// TODO: Separate header file for this
class RDKIT_DISTGEOMETRY_EXPORT TorsionSet {
 public:
  unsigned int d_idx0;  
  unsigned int d_idx1;
  unsigned int d_idx2;
  unsigned int d_idx3;
  double d_torsion;
  
  TorsionSet(unsigned int pid0, unsigned int pid1, unsigned int pid2,
            unsigned int pid3, double torsion)
      : d_idx0(pid0),
        d_idx1(pid1),
        d_idx2(pid2),
        d_idx3(pid3),
        d_torsion(torsion)
	  {
    CHECK_INVARIANT(torsion <= M_PI, "Inconsistent torsion\n");
    CHECK_INVARIANT(torsion >= -M_PI, "Inconsistent torsion\n");
    d_torsion = torsion;
  }

  inline double getTorsion() const { return d_torsion; }

};

typedef boost::shared_ptr<TorsionSet> TorsionSetPtr;
typedef std::vector<TorsionSetPtr> VECT_TORSIONSET;
}  // namespace DistGeom

#endif
