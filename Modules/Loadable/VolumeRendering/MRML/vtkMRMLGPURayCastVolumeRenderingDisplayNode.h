/*==============================================================================

  Program: 3D Slicer

  Copyright (c) Kitware Inc.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Julien Finet, Kitware Inc.
  and was partially funded by NIH grant 3P41RR013218-12S1

==============================================================================*/

#ifndef __vtkMRMLGPURayCastVolumeRenderingDisplayNode_h
#define __vtkMRMLGPURayCastVolumeRenderingDisplayNode_h

// Volume Rendering includes
#include "vtkMRMLVolumeRenderingDisplayNode.h"

/// \ingroup Slicer_QtModules_VolumeRendering
/// \name vtkMRMLGPURayCastGPURayCastVolumeRenderingDisplayNode
/// \brief MRML node for storing information for GPU Raycast Volume Rendering
class VTK_SLICER_VOLUMERENDERING_MODULE_MRML_EXPORT vtkMRMLGPURayCastVolumeRenderingDisplayNode
  : public vtkMRMLVolumeRenderingDisplayNode
{
public:
  static vtkMRMLGPURayCastVolumeRenderingDisplayNode *New();
  vtkTypeMacro(vtkMRMLGPURayCastVolumeRenderingDisplayNode,vtkMRMLVolumeRenderingDisplayNode);
  virtual void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;

  virtual vtkMRMLNode* CreateNodeInstance() VTK_OVERRIDE;

  // Description:
  // Set node attributes
  virtual void ReadXMLAttributes( const char** atts) VTK_OVERRIDE;

  // Description:
  // Write this node's information to a MRML file in XML format.
  virtual void WriteXML(ostream& of, int indent) VTK_OVERRIDE;

  // Description:
  // Copy the node's attributes to this object
  virtual void Copy(vtkMRMLNode *node) VTK_OVERRIDE;

  // Description:
  // Get node XML tag name (like Volume, Model)
  virtual const char* GetNodeTagName() VTK_OVERRIDE {return "GPURayCastVolumeRendering";}

  // Description:
  // Ray cast technique
  vtkGetMacro (RaycastTechnique, int);
  vtkSetMacro (RaycastTechnique, int);

protected:
  vtkMRMLGPURayCastVolumeRenderingDisplayNode();
  ~vtkMRMLGPURayCastVolumeRenderingDisplayNode();
  vtkMRMLGPURayCastVolumeRenderingDisplayNode(const vtkMRMLGPURayCastVolumeRenderingDisplayNode&);
  void operator=(const vtkMRMLGPURayCastVolumeRenderingDisplayNode&);

  /* techniques in GPU ray cast
   * 0: composite with directional lighting (default)
   * 2: MIP
   * 3: MINIP
   * */
  int RaycastTechnique;
};

#endif

