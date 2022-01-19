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

class Vector4 {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.quad = null;
    }
    else {
      if (initObj.hasOwnProperty('quad')) {
        this.quad = initObj.quad
      }
      else {
        this.quad = new Array(4).fill(0);
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Vector4
    // Check that the constant length array field [quad] has the right length
    if (obj.quad.length !== 4) {
      throw new Error('Unable to serialize array field quad - length must be 4')
    }
    // Serialize message field [quad]
    bufferOffset = _arraySerializer.float32(obj.quad, buffer, bufferOffset, 4);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Vector4
    let len;
    let data = new Vector4(null);
    // Deserialize message field [quad]
    data.quad = _arrayDeserializer.float32(buffer, bufferOffset, 4)
    return data;
  }

  static getMessageSize(object) {
    return 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'actuators/Vector4';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '390dd8b5493d1ef8649e084b0a6daa79';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32[4] quad
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Vector4(null);
    if (msg.quad !== undefined) {
      resolved.quad = msg.quad;
    }
    else {
      resolved.quad = new Array(4).fill(0)
    }

    return resolved;
    }
};

module.exports = Vector4;
