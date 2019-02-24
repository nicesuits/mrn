[%bs.raw {|require('./IssueRow.css')|}];

let component = ReasonReact.statelessComponent("IssueRow");

let make = (~issue: IssueType.issue, _children) => {
  ...component,
  render: _self =>
    <tr>
      <td> {ReasonReact.string(string_of_int(issue.id))} </td>
      <td> {ReasonReact.string(issue.status)} </td>
      <td> {ReasonReact.string(issue.owner)} </td>
      <td> {ReasonReact.string(issue.created)} </td>
      <td> {ReasonReact.string(string_of_int(issue.effort))} </td>
      <td> {ReasonReact.string(issue.completedDate)} </td>
      <td> {ReasonReact.string(issue.title)} </td>
    </tr>,
};