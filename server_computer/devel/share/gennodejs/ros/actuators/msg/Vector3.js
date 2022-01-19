// Auto-generated. Do not edit!

// (in-package actuators.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class Vector3 {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.tri = null;
    }
    else {
      if (initObj.hasOwnProperty('tri')) {
        this.tri = initObj.tri
      }
      else {
        this.tri = new Array(3).fill(0);
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Vector3
    // Check that the constant length array field [tri] has the right length
    if (obj.tri.length !== 3) {
      throw new Error('Unable to serialize array field tri - length must be 3')
    }
    // Serialize message field [tri]
    bufferOffset = _arraySerializer.float32(obj.tri, buffer, bufferOffset, 3);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Vector3
    let len;
    let data = new Vector3(null);
    // Deserialize message field [tri]
    data.tri = _arrayDeserializer.float32(buffer, bufferOffset, 3)
    return data;
  }

  static getMessageSize(object) {
    return 12;
  }

  static datatype() {
    // Returns string type for a message object
    return 'actuators/Vector3';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '8c49180465985aea8f1b4c8c15017d58';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32[3] tri
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Vector3(null);
    if (msg.tri !== undefined) {
      resolved.tri = msg.tri;
    }
    else {
      resolved.tri = new Array(3).fill(0)
    }

    return resolved;
    }
};

module.exports = Vector3;
