#include <jni.h>
#include <stdio.h>
#include <libperfstat.h>
#include "com_ibm_aix_perfstat.h"

int setString(JNIEnv *env, jobject obj, char *fieldName, char *valueStr) {
	/* Get a reference to objbs class */
        jclass cls = (*env)->GetObjectClass(env, obj);

        /* Look for the instance field s in cls */
        jfieldID fid = (*env)->GetFieldID(env, cls, fieldName, "Ljava/lang/String;");
        if (fid == NULL) {
                return -1; /* failed to find the field */
        }
        jstring jstr = (*env)->NewStringUTF(env, valueStr);
        if (jstr == NULL) {
                return -1; /* out of memory */
        }
        (*env)->SetObjectField(env, obj, fid, jstr);
        return 0;
}

int setLong(JNIEnv *env, jobject obj, char *fieldName, long value) {
	/* Get a reference to objbs class */
        jclass cls = (*env)->GetObjectClass(env, obj);

        /* Look for the instance field s in cls */
        jfieldID fid = (*env)->GetFieldID(env, cls, fieldName, "J");
        if (fid == NULL) {
                return -1; /* failed to find the field */
        }
        (*env)->SetLongField(env, obj, fid, (jlong)value);
        return 0;
}

int setInt(JNIEnv *env, jobject obj, char *fieldName, int value) {
	/* Get a reference to objbs class */
        jclass cls = (*env)->GetObjectClass(env, obj);

        /* Look for the instance field s in cls */
        jfieldID fid = (*env)->GetFieldID(env, cls, fieldName, "I");
        if (fid == NULL) {
                return -1; /* failed to find the field */
        }
        (*env)->SetIntField(env, obj, fid, value);
        return 0;
}

JNIEXPORT void JNICALL
Java_com_ibm_aix_LparConfig_getConfig
(JNIEnv *env, jobject obj)
{
	perfstat_partition_config_t pconfig;

	/* Create a new string and overwrite the instance field */
	if (perfstat_partition_config(NULL , &pconfig, sizeof(perfstat_partition_config_t), 1) <= 0){
	       perror("perfstat_cpu_total ");
	       exit(1);
	}

	if (setString(env, obj, "hostname", pconfig.partitionname))
		return; /* failed to find the field */
	if (setString(env, obj, "processorFamily", pconfig.processorFamily))
		return; /* failed to find the field */
	if (setString(env, obj, "OSBuild", pconfig.OSBuild))
		return; /* failed to find the field */
	if (setLong(env, obj, "drives", pconfig.drives))
		return; /* failed to find the field */
	if (setInt(env, obj, "lcpus", pconfig.lcpus))
		return; /* failed to find the field */

	return ;
}

