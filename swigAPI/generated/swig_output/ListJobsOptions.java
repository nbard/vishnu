/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.40
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.sysfera.vishnu.api.vishnu.internal;

public class ListJobsOptions extends EObject {
  private long swigCPtr;

  protected ListJobsOptions(long cPtr, boolean cMemoryOwn) {
    super(VISHNUJNI.SWIGListJobsOptionsUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(ListJobsOptions obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        VISHNUJNI.delete_ListJobsOptions(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public ListJobsOptions() {
    this(VISHNUJNI.new_ListJobsOptions(), true);
  }

  public void _initialize() {
    VISHNUJNI.ListJobsOptions__initialize(swigCPtr, this);
  }

  public String getJobId() {
    return VISHNUJNI.ListJobsOptions_getJobId(swigCPtr, this);
  }

  public void setJobId(String _jobId) {
    VISHNUJNI.ListJobsOptions_setJobId(swigCPtr, this, _jobId);
  }

  public int getNbCpu() {
    return VISHNUJNI.ListJobsOptions_getNbCpu(swigCPtr, this);
  }

  public void setNbCpu(int _nbCpu) {
    VISHNUJNI.ListJobsOptions_setNbCpu(swigCPtr, this, _nbCpu);
  }

  public long getFromSubmitDate() {
    return VISHNUJNI.ListJobsOptions_getFromSubmitDate(swigCPtr, this);
  }

  public void setFromSubmitDate(long _fromSubmitDate) {
    VISHNUJNI.ListJobsOptions_setFromSubmitDate(swigCPtr, this, _fromSubmitDate);
  }

  public long getToSubmitDate() {
    return VISHNUJNI.ListJobsOptions_getToSubmitDate(swigCPtr, this);
  }

  public void setToSubmitDate(long _toSubmitDate) {
    VISHNUJNI.ListJobsOptions_setToSubmitDate(swigCPtr, this, _toSubmitDate);
  }

  public String getOwner() {
    return VISHNUJNI.ListJobsOptions_getOwner(swigCPtr, this);
  }

  public void setOwner(String _owner) {
    VISHNUJNI.ListJobsOptions_setOwner(swigCPtr, this, _owner);
  }

  public int getStatus() {
    return VISHNUJNI.ListJobsOptions_getStatus(swigCPtr, this);
  }

  public void setStatus(int _status) {
    VISHNUJNI.ListJobsOptions_setStatus(swigCPtr, this, _status);
  }

  public int getPriority() {
    return VISHNUJNI.ListJobsOptions_getPriority(swigCPtr, this);
  }

  public void setPriority(int _priority) {
    VISHNUJNI.ListJobsOptions_setPriority(swigCPtr, this, _priority);
  }

  public String getQueue() {
    return VISHNUJNI.ListJobsOptions_getQueue(swigCPtr, this);
  }

  public void setQueue(String _queue) {
    VISHNUJNI.ListJobsOptions_setQueue(swigCPtr, this, _queue);
  }

  public String getMultipleStatus() {
    return VISHNUJNI.ListJobsOptions_getMultipleStatus(swigCPtr, this);
  }

  public void setMultipleStatus(String _multipleStatus) {
    VISHNUJNI.ListJobsOptions_setMultipleStatus(swigCPtr, this, _multipleStatus);
  }

  public boolean isBatchJob() {
    return VISHNUJNI.ListJobsOptions_isBatchJob(swigCPtr, this);
  }

  public void setBatchJob(boolean _batchJob) {
    VISHNUJNI.ListJobsOptions_setBatchJob(swigCPtr, this, _batchJob);
  }

  public SWIGTYPE_p_ecorecpp__mapping__any eGet(int _featureID, boolean _resolve) {
    return new SWIGTYPE_p_ecorecpp__mapping__any(VISHNUJNI.ListJobsOptions_eGet(swigCPtr, this, _featureID, _resolve), true);
  }

  public void eSet(int _featureID, SWIGTYPE_p_ecorecpp__mapping__any _newValue) {
    VISHNUJNI.ListJobsOptions_eSet(swigCPtr, this, _featureID, SWIGTYPE_p_ecorecpp__mapping__any.getCPtr(_newValue));
  }

  public boolean eIsSet(int _featureID) {
    return VISHNUJNI.ListJobsOptions_eIsSet(swigCPtr, this, _featureID);
  }

  public void eUnset(int _featureID) {
    VISHNUJNI.ListJobsOptions_eUnset(swigCPtr, this, _featureID);
  }

  public SWIGTYPE_p_ecore__EClass _eClass() {
    long cPtr = VISHNUJNI.ListJobsOptions__eClass(swigCPtr, this);
    return (cPtr == 0) ? null : new SWIGTYPE_p_ecore__EClass(cPtr, false);
  }

}
