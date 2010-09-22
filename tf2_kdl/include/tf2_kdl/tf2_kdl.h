/*
 * Copyright (c) 2008, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/** \author Wim Meeussen */

#ifndef TF2_KDL_H
#define TF2_KDL_H

#include <tf2_cpp/tf2_cpp_core.h>
#include <kdl/frames.hpp>


namespace tf2
{
    
KDL::Frame transformToKDL(const geometry_msgs::TransformStamped& t)
  {
    return KDL::Frame(KDL::Rotation::Quaternion(t.transform.rotation.x, t.transform.rotation.y, 
						t.transform.rotation.z, t.transform.rotation.w),
		      KDL::Vector(t.transform.translation.x, t.transform.translation.y, t.transform.translation.z));
  }


// this method needs to be implemented by client library developers
template <>
  void doTransform(const tf2::Stamped<KDL::Vector>& t_in, tf2::Stamped<KDL::Vector>& t_out, const geometry_msgs::TransformStamped& transform)
  {
    t_out = tf2::Stamped<KDL::Vector>(transformToKDL(transform) * t_in, transform.header.stamp, transform.header.frame_id);
  }

// this method needs to be implemented by client library developers
template <>
  void doTransform(const tf2::Stamped<KDL::Twist>& t_in, tf2::Stamped<KDL::Twist>& t_out, const geometry_msgs::TransformStamped& transform)
  {
    t_out = tf2::Stamped<KDL::Twist>(transformToKDL(transform) * t_in, transform.header.stamp, transform.header.frame_id);
  }

// this method needs to be implemented by client library developers
template <>
  void doTransform(const tf2::Stamped<KDL::Wrench>& t_in, tf2::Stamped<KDL::Wrench>& t_out, const geometry_msgs::TransformStamped& transform)
  {
    t_out = tf2::Stamped<KDL::Wrench>(transformToKDL(transform) * t_in, transform.header.stamp, transform.header.frame_id);
  }

// this method needs to be implemented by client library developers
template <>
  void doTransform(const tf2::Stamped<KDL::Frame>& t_in, tf2::Stamped<KDL::Frame>& t_out, const geometry_msgs::TransformStamped& transform)
  {
    t_out = tf2::Stamped<KDL::Frame>(transformToKDL(transform) * t_in, transform.header.stamp, transform.header.frame_id);
  }



} // namespace

#endif // TF2_CPP_H