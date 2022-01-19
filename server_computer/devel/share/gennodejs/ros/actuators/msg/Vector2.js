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

class Vector2 {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.dual = null;
    }
    else {
      if (initObj.hasOwnProperty('dual')) {
        this.dual = initObj.dual
      }
      else {
        this.dual = new Array(2).fill(0);
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Vector2
    // Check that the constant length array field [dual] has the right length
    if (obj.dual.length !== 2) {
      throw new Error('Unable to serialize array field dual - length must be 2')
    }
    // Serialize message field [dual]
    bufferOffset = _arraySerializer.float32(obj.dual, buffer, bufferOffset, 2);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Vector2
    let len;
    let data = new Vector2(null);
    // Deserialize message field [dual]
    data.dual = _arrayDeserializer.float32(buffer, bufferOffset, 2)
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'actuators/Vector2';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'dc6fc6947e0b42110f3e03b6150ecb68';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32[2] dual
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Vector2(null);
    if (msg.dual !== undefined) {
      resolved.dual = msg.dual;
    }
    else {
      resolved.dual = new Array(2).fill(0)
    }

    return resolved;
    }
};

module.exports = Vector2;
