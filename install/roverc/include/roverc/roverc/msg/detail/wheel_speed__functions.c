// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from roverc:msg/WheelSpeed.idl
// generated code does not contain a copyright notice
#include "roverc/msg/detail/wheel_speed__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
roverc__msg__WheelSpeed__init(roverc__msg__WheelSpeed * msg)
{
  if (!msg) {
    return false;
  }
  // front_right
  // front_left
  // rear_right
  // rear_left
  return true;
}

void
roverc__msg__WheelSpeed__fini(roverc__msg__WheelSpeed * msg)
{
  if (!msg) {
    return;
  }
  // front_right
  // front_left
  // rear_right
  // rear_left
}

bool
roverc__msg__WheelSpeed__are_equal(const roverc__msg__WheelSpeed * lhs, const roverc__msg__WheelSpeed * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // front_right
  if (lhs->front_right != rhs->front_right) {
    return false;
  }
  // front_left
  if (lhs->front_left != rhs->front_left) {
    return false;
  }
  // rear_right
  if (lhs->rear_right != rhs->rear_right) {
    return false;
  }
  // rear_left
  if (lhs->rear_left != rhs->rear_left) {
    return false;
  }
  return true;
}

bool
roverc__msg__WheelSpeed__copy(
  const roverc__msg__WheelSpeed * input,
  roverc__msg__WheelSpeed * output)
{
  if (!input || !output) {
    return false;
  }
  // front_right
  output->front_right = input->front_right;
  // front_left
  output->front_left = input->front_left;
  // rear_right
  output->rear_right = input->rear_right;
  // rear_left
  output->rear_left = input->rear_left;
  return true;
}

roverc__msg__WheelSpeed *
roverc__msg__WheelSpeed__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  roverc__msg__WheelSpeed * msg = (roverc__msg__WheelSpeed *)allocator.allocate(sizeof(roverc__msg__WheelSpeed), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(roverc__msg__WheelSpeed));
  bool success = roverc__msg__WheelSpeed__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
roverc__msg__WheelSpeed__destroy(roverc__msg__WheelSpeed * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    roverc__msg__WheelSpeed__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
roverc__msg__WheelSpeed__Sequence__init(roverc__msg__WheelSpeed__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  roverc__msg__WheelSpeed * data = NULL;

  if (size) {
    data = (roverc__msg__WheelSpeed *)allocator.zero_allocate(size, sizeof(roverc__msg__WheelSpeed), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = roverc__msg__WheelSpeed__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        roverc__msg__WheelSpeed__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
roverc__msg__WheelSpeed__Sequence__fini(roverc__msg__WheelSpeed__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      roverc__msg__WheelSpeed__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

roverc__msg__WheelSpeed__Sequence *
roverc__msg__WheelSpeed__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  roverc__msg__WheelSpeed__Sequence * array = (roverc__msg__WheelSpeed__Sequence *)allocator.allocate(sizeof(roverc__msg__WheelSpeed__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = roverc__msg__WheelSpeed__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
roverc__msg__WheelSpeed__Sequence__destroy(roverc__msg__WheelSpeed__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    roverc__msg__WheelSpeed__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
roverc__msg__WheelSpeed__Sequence__are_equal(const roverc__msg__WheelSpeed__Sequence * lhs, const roverc__msg__WheelSpeed__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!roverc__msg__WheelSpeed__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
roverc__msg__WheelSpeed__Sequence__copy(
  const roverc__msg__WheelSpeed__Sequence * input,
  roverc__msg__WheelSpeed__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(roverc__msg__WheelSpeed);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    roverc__msg__WheelSpeed * data =
      (roverc__msg__WheelSpeed *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!roverc__msg__WheelSpeed__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          roverc__msg__WheelSpeed__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!roverc__msg__WheelSpeed__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
