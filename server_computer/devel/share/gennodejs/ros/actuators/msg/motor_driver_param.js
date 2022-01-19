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

class motor_driver_param {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.id = null;
      this.dir1 = null;
      this.dir2 = null;
      this.pwm = null;
    }
    else {
      if (initObj.hasOwnProperty('id')) {
        this.id = initObj.id
      }
      else {
        this.id = 0;
      }
      if (initObj.hasOwnProperty('dir1')) {
        this.dir1 = initObj.dir1
      }
      else {
        this.dir1 = 0;
      }
      if (initObj.hasOwnProperty('dir2')) {
        this.dir2 = initObj.dir2
      }
      else {
        this.dir2 = 0;
      }
      if (initObj.hasOwnProperty('pwm')) {
        this.pwm = initObj.pwm
      }
      else {
        this.pwm = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type motor_driver_param
    // Serialize message field [id]
    bufferOffset = _serializer.uint8(obj.id, buffer, bufferOffset);
    // Serialize message field [dir1]
    bufferOffset = _serializer.uint8(obj.dir1, buffer, bufferOffset);
    // Serialize message field [dir2]
    bufferOffset = _serializer.uint8(obj.dir2, buffer, bufferOffset);
    // Serialize message field [pwm]
    bufferOffset = _serializer.uint16(obj.pwm, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type motor_driver_param
    let len;
    let data = new motor_driver_param(null);
    // Deserialize message field [id]
    data.id = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [dir1]
    data.dir1 = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [dir2]
    data.dir2 = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [pwm]
    data.pwm = _deserializer.uint16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 5;
  }

  static datatype() {
    // Returns string type for a message object
    return 'actuators/motor_driver_param';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '4dd7daa3fbb798d83aefe25263d7d1e1';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    #motor driving param
    uint8 id
    uint8 dir1
    uint8 dir2
    uint16 pwm
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new motor_driver_param(null);
    if (msg.id !== undefined) {
      resolved.id = msg.id;
    }
    else {
      resolved.id = 0
    }

    if (msg.dir1 !== undefined) {
      resolved.dir1 = msg.dir1;
    }
    else {
      resolved.dir1 = 0
    }

    if (msg.dir2 !== undefined) {
      resolved.dir2 = msg.dir2;
    }
    else {
      resolved.dir2 = 0
    }

    if (msg.pwm !== undefined) {
      resolved.pwm = msg.pwm;
    }
    else {
      resolved.pwm = 0
    }

    return resolved;
    }
};

module.exports = motor_driver_param;
